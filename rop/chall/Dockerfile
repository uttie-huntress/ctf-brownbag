FROM alpine:latest

# Install build tools, cmake, debugger, binutils, and Python build headers
RUN apk add --no-cache \
    build-base \
    cmake \
    git \
    linux-headers \
    binutils \
    gdb \
    bash \
    make \
    python3 \
    py3-pip \
    python3-dev \
    libffi-dev \
    openssl-dev \
    strace

# Install pwntools
RUN pip install --no-cache-dir --break-system-packages pwntools

WORKDIR /challenge

COPY babyrop.c .
COPY Makefile .
COPY exploit_aslr.py .
COPY exploit.py .

# Build the vulnerable binary into the image so gdb has a target ready.
RUN make build

# gdb quality-of-life for live demos (ASLR off under gdb is already the default).
RUN printf 'set pagination off\nset disassembly-flavor intel\n' > /root/.gdbinit

# NOTE: ptrace/gdb is a RUNTIME concern, not a build one. Capabilities and
# seccomp cannot be granted here -- run the container with the flags in the
# Makefile's `dshell` target (--cap-add=SYS_PTRACE --security-opt seccomp=unconfined).
CMD ["/bin/bash"]
