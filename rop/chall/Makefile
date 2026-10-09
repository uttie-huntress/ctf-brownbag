all: build

build:
	gcc -fno-pie -no-pie -Wno-implicit-function-declaration -fno-stack-protector babyrop.c -static -o babyrop

dbuild:
	docker build -t babyrop-chall .

drun:
	docker run --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined babyrop-chall
