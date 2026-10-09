all: build

build:
	gcc -fno-pie -no-pie -Wno-implicit-function-declaration -fno-stack-protector babyrop.c -static -o babyrop

dbuild:
	docker build --platform linux/amd64 -t babyrop-chall .

dshell:
	docker run --platform linux/amd64 --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined babyrop-chall
