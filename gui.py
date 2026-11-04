import os
import subprocess
import threading
import tkinter as tk
from tkinter import messagebox, scrolledtext, ttk


class CppAppGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("GitAI Studio - Enhanced C++ Builder v2.0")
        self.root.geometry("800x680")
        self.root.minsize(700, 560)

        # Theme state: 'light' or 'dark'
        self.current_theme = "light"

        # Style configuration
        self.style = ttk.Style()
        self.style.theme_use("clam")

        # Main Frame
        self.main_frame = ttk.Frame(root, padding="12 12 12 12")
        self.main_frame.pack(fill=tk.BOTH, expand=True)

        # Top Header Frame (Title + Theme Switch)
        header_frame = ttk.Frame(self.main_frame)
        header_frame.pack(fill=tk.X, pady=(0, 10))

        title_label = ttk.Label(
            header_frame,
            text="Enhanced C++ Project Build, Test & Management Suite",
            font=("Helvetica", 14, "bold"),
        )
        title_label.pack(side=tk.LEFT, anchor=tk.W)

        self.theme_btn = ttk.Button(
            header_frame,
            text="Switch to Dark Theme",
            command=self.toggle_theme,
        )
        self.theme_btn.pack(side=tk.RIGHT, anchor=tk.E)

        # Buttons Frame
        self.btn_frame = ttk.LabelFrame(self.main_frame, text=" Actions ", padding=10)
        self.btn_frame.pack(fill=tk.X, pady=(0, 10))

        self.btn_configure = ttk.Button(
            self.btn_frame,
            text="1. Configure CMake",
            command=self.run_configure,
        )
        self.btn_configure.grid(row=0, column=0, padx=5, pady=5, sticky="ew")

        self.btn_build = ttk.Button(
            self.btn_frame,
            text="2. Build Project",
            command=self.run_build,
        )
        self.btn_build.grid(row=0, column=1, padx=5, pady=5, sticky="ew")

        self.btn_test = ttk.Button(
            self.btn_frame,
            text="3. Run Tests",
            command=self.run_tests,
        )
        self.btn_test.grid(row=0, column=2, padx=5, pady=5, sticky="ew")

        self.btn_run = ttk.Button(
            self.btn_frame,
            text="4. Run Executable",
            command=self.run_executable,
        )
        self.btn_run.grid(row=0, column=3, padx=5, pady=5, sticky="ew")

        for i in range(4):
            self.btn_frame.columnconfigure(i, weight=1)

        # Output Console Frame
        console_frame = ttk.LabelFrame(
            self.main_frame, text=" Build Log / Output Console ", padding=10
        )
        console_frame.pack(fill=tk.BOTH, expand=True, pady=(0, 10))

        self.console = scrolledtext.ScrolledText(
            console_frame, wrap=tk.WORD, font=("Courier", 10)
        )
        self.console.pack(fill=tk.BOTH, expand=True)
        self.console.config(state=tk.DISABLED)

        # Status Bar & Clear Button Frame
        bottom_frame = ttk.Frame(self.main_frame)
        bottom_frame.pack(fill=tk.X)

        self.status_var = tk.StringVar()
        self.status_var.set("Ready")
        self.status_bar = ttk.Label(
            bottom_frame,
            textvariable=self.status_var,
            relief=tk.SUNKEN,
            anchor=tk.W,
        )
        self.status_bar.pack(side=tk.LEFT, fill=tk.X, expand=True)

        clear_btn = ttk.Button(bottom_frame, text="Clear Console", command=self.clear_console)
        clear_btn.pack(side=tk.RIGHT, padx=(5, 0))

        # Apply initial theme
        self.apply_theme()

    def toggle_theme(self):
        if self.current_theme == "light":
            self.current_theme = "dark"
            self.theme_btn.config(text="Switch to Light Theme")
        else:
            self.current_theme = "light"
            self.theme_btn.config(text="Switch to Dark Theme")
        self.apply_theme()

    def apply_theme(self):
        if self.current_theme == "dark":
            bg_color = "#1e1e1e"
            fg_color = "#d4d4d4"
            console_bg = "#121212"
            console_fg = "#00ff00"
            self.root.config(bg=bg_color)
        else:
            bg_color = "#f0f0f0"
            fg_color = "#000000"
            console_bg = "#ffffff"
            console_fg = "#000000"
            self.root.config(bg="#ffffff")

        # Configure ScrolledText console colors
        self.console.config(
            bg=console_bg,
            fg=console_fg,
            insertbackground=fg_color,
        )

    def log(self, message):
        self.console.config(state=tk.NORMAL)
        self.console.insert(tk.END, message + "\n")
        self.console.see(tk.END)
        self.console.config(state=tk.DISABLED)

    def clear_console(self):
        self.console.config(state=tk.NORMAL)
        self.console.delete("1.0", tk.END)
        self.console.config(state=tk.DISABLED)

    def set_buttons_state(self, state):
        for btn in [
            self.btn_configure,
            self.btn_build,
            self.btn_test,
            self.btn_run,
            self.theme_btn,
        ]:
            btn.config(state=state)

    def run_command_threaded(self, cmd_list, working_dir="."):
        def worker():
            self.set_buttons_state(tk.DISABLED)
            self.status_var.set(f"Running: {' '.join(cmd_list)}...")
            self.log(f">>> Executing: {' '.join(cmd_list)}")

            try:
                process = subprocess.Popen(
                    cmd_list,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.STDOUT,
                    text=True,
                    cwd=working_dir,
                )

                while True:
                    output = process.stdout.readline()
                    if output == "" and process.poll() is not None:
                        break
                    if output:
                        self.log(output.strip())

                rc = process.poll()
                if rc == 0:
                    self.log(">>> Command succeeded.\n")
                    self.status_var.set("Ready - Success")
                else:
                    self.log(f">>> Command failed with exit code {rc}.\n")
                    self.status_var.set(f"Error: Exit code {rc}")
            except Exception as e:
                self.log(f">>> Exception occurred: {str(e)}\n")
                self.status_var.set("Error occurred")
            finally:
                self.set_buttons_state(tk.NORMAL)

        threading.Thread(target=worker, daemon=True).start()

    def run_configure(self):
        build_dir = "build"
        if not os.path.exists(build_dir):
            os.makedirs(build_dir)
        self.run_command_threaded(["cmake", ".."], working_dir=build_dir)

    def run_build(self):
        build_dir = "build"
        if not os.path.exists(build_dir):
            messagebox.showwarning(
                "Not Configured",
                "Please run 'Configure CMake' first!",
            )
            return
        self.run_command_threaded(
            ["cmake", "--build", ".", "--config", "Release"],
            working_dir=build_dir,
        )

    def run_tests(self):
        build_dir = "build"
        if not os.path.exists(build_dir):
            messagebox.showwarning(
                "Not Built", "Please build the project first!"
            )
            return
        self.run_command_threaded(
            ["ctest", "--output-on-failure", "-C", "Release"],
            working_dir=build_dir,
        )

    def run_executable(self):
        if os.name == "nt":
            exe_candidates = [
                os.path.join("build", "Release", "app_exec.exe"),
                os.path.join("build", "app_exec.exe"),
            ]
        else:
            exe_candidates = [
                os.path.join("build", "app_exec"),
                os.path.join("build", "Release", "app_exec"),
            ]

        exe_path = None
        for candidate in exe_candidates:
            if os.path.exists(candidate):
                exe_path = candidate
                break

        if not exe_path:
            messagebox.showerror(
                "Executable Not Found",
                "Could not find built executable 'app_exec'. Please build the project first.",
            )
            return

        self.run_command_threaded([os.path.abspath(exe_path)])


if __name__ == "__main__":
    root = tk.Tk()
    app = CppAppGUI(root)
    root.mainloop()
