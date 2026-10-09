# ROP 101 Challenge

A foundational Return-Oriented Programming (ROP) CTF challenge designed for the Cybersecurity Awareness Month brown bag series.

## Objective
Exploit a classic buffer overflow via `gets()` to hijack the instruction pointer, locate a `pop rdi; ret` gadget, and successfully execute `target("/bin/sh")`.

## Files
* `babyrop.c`: The vulnerable target source code.
* `Dockerfile`: Alpine-based environment pre-tooled with `gdb`, `binutils`, and python. Compiles the binary with mitigations intentionally disabled.

## Quick Start

**1. Build the container:**
```bash
docker build -t babyrop-chall .
