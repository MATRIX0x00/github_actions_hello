import datetime

def main():
    now = datetime.datetime.utcnow().isoformat()
    filename = f"hello_{now.replace(':', '-')}.txt"
    with open(filename, "w") as f:
        f.write(f"Hello at {now}\n")
    print(f"Created file {filename}")

if __name__ == "__main__":
    main()
