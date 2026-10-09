FROM alpine:latest

# Install build essential tools, debugger, binutils, and utilities
RUN apk add --no-cache \
    build-base \
    binutils \
    gdb \
    bash \
    python3 \
    py3-pip \
    strace

# Set working directory
WORKDIR /challenge

# Copy the source file into the container
COPY babyrop.c .
COPY Makefile .

# Compile the binary with all modern mitigations disabled
# Note: musl-libc natively supports static linking
RUN gcc -fno-pie -no-pie -Wno-implicit-function-declaration -fno-stack-protector babyrop.c -static -o babyrop

# Set interactive bash as the default entry point
CMD ["/bin/bash"]
