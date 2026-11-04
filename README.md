# Hourly Hello Bot

This repository contains a GitHub Actions workflow that runs automated tasks, HTTP requests, and scheduled scripts.

## Architecture 🏗️
- **.github/workflows/hourly_hello.yml**: The core cron scheduler.
- **hello.py**: A Python script that generates a timestamped text file saying hello.

## Setup & Usage ⚙️
1. Push this repository to GitHub.
2. Go to Settings > Actions > General > Workflow permissions and select **Read and write permissions**.