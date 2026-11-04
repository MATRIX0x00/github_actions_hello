# Hourly Hello Bot

This repository contains a GitHub Actions workflow that runs every single hour, executes a Python script, and commits a new timestamped hello file to your repository.

## Architecture 🏗️
- **.github/workflows/hourly_hello.yml**: The core cron scheduler running every hour (`0 * * * *`).
- **hello.py**: A Python script that generates a timestamped text file saying hello.

## Setup & Usage ⚙️
1. Push this repository to GitHub.
2. Go to Settings > Actions > General > Workflow permissions and select **Read and write permissions**.
3. The workflow will commit an update every hour.

// [Codelazr Edit]: add new file called how.md have some info

