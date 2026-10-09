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

CMD ["/bin/bash"]
