# LASAL Class 2 — Git Integration Demo

This project serves as a sandbox for testing Git workflows with LASAL Class 2 projects,
starting with `.gitignore` configuration to identify which generated/binary files
should be excluded from version control.

## Project Configuration

| Setting           | Value                       |
|-------------------|-----------------------------|
| LASAL Class 2     | v02.02.254 (Build: 21080)   |
| Compiler version  | 79                          |
| OPC UA            | Enabled                     |
| Hardware          | CPU313 SCP211 + IO + AXIS   |

## Goals

- Determine which LASAL project files are safe to track in Git
- Identify generated, binary, or user-specific files to exclude via `.gitignore`
- Establish a clean repository structure as a baseline for future LASAL projects

## `.gitignore` Strategy

The key question for any LASAL project is which files are:

- **Generated at build time** → should be ignored
- **User/machine-specific** (e.g. workspace layout, paths) → should be ignored  
- **Essential for reproducible builds** (source, config, hardware definition) → should be tracked

Findings will be documented here as testing progresses.

## Status

🔬 Work in progress — actively testing `.gitignore` configuration