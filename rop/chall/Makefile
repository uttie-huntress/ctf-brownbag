all: build

build:
	gcc -fno-pie -no-pie -Wno-implicit-function-declaration -fno-stack-protector babyrop.c -static -o babyrop

dbuild:
	docker build --platform linux/amd64 -t babyrop-chall .

# Debuggable shell: ptrace/gdb enabled (grant SYS_PTRACE, turn seccomp off).
dshell:
	docker run --platform linux/amd64 --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined babyrop-chall

# Locked-down shell: ptrace/gdb blocked (default seccomp, capability dropped).
dshell-noptrace:
	docker run --platform linux/amd64 --rm -it --cap-drop=SYS_PTRACE babyrop-chall

# Host/VM only: relax Yama so gdb can ATTACH to a running pid (not just launch it).
# ptrace_scope is NOT namespaced, so it cannot go in docker run -- set it here.
# Usually unnecessary: SYS_PTRACE (dshell) already overrides Yama.
yama-off:
	sudo sysctl -w kernel.yama.ptrace_scope=0

yama-on:
	sudo sysctl -w kernel.yama.ptrace_scope=1

.PHONY: all build dbuild dshell dshell-noptrace yama-off yama-on
