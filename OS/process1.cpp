#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    cout << "현재 프로세스 PID" << getpid() << endl;
    cout << "자식 프로세스 생성" << endl;
    pid_t pid = fork();

    if (pid < 0){
        cout << "fork 실패" << endl;
        return 1;
    }
    else if (pid == 0){
        cout << "자식 프로세스 PID : " << getpid() << ", 부모 프로세스 PID : " << getppid() << endl;
    }
    
    return 0;
}