#include <stdio.h>
#include <unistd.h>

void target(char* executable){
    char* argv[]={executable,NULL};
    printf("Jackpot! Now going to run %s\n",executable);
    execve(executable,argv,NULL);
}

int vuln(){
    char buf[16];
    gets(buf);
    return 0;
}

int main(){
    setbuf(stdin,NULL);
    setbuf(stdout,NULL);
    puts("Gimme some data!");
    fflush(stdout);
    vuln();
    puts("Failed... :(");
}
