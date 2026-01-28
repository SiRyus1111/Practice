#include <iostream>
#include <chrono>

int main(){
    static int array[10000][10000] = {1, }; // 배열 생성, 모든 원소 1로 초기화
    
    auto start1 = std::chrono::steady_clock::now(); // 현재 시간 재는 함수로 for문 시작 시간 기록
    int sum1 = 0; // 컴파일러가 for문을 실행하게 하기 위해서 사용하는 변수
    // (컴파일러가 똑똑해서 실행할 의미가 없는 for문같은건 실행안함)

    for (int i = 0; i < 10000; i++){
        for (int j = 0; j < 10000; j++){   // i -> j 순서로 배열에 접근
            sum1 += array[i][j];
        }
    }

    auto end1 = std::chrono::steady_clock::now(); // 현재 시간 재는 함수로 for문 종료 시간 기록
    auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1); // i -> j 순서로 배열에 접근했을 때 배열 접근 시간 기록(종료 시간 - 시작 시간, 마이크로초)
    
    auto start2 = std::chrono::steady_clock::now(); // 현재 시간 재는 함수로 for문 시작 시간 기록
    int sum2 = 0; // 컴파일러가 for문을 실행하게 하기 위해서 사용하는 변수
    
    for (int i = 0; i < 10000; i++){
        for (int j = 0; j < 10000; j++){   // j -> i 순서로 배열에 접근
            sum2 += array[j][i];
        }
    }

    auto end2 = std::chrono::steady_clock::now(); // 현재 시간 재는 함수로 for문 종료 시간 기록
    auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end2-start2); // j -> i 순서로 배열에 접근했을 때 배열 접근 시간 기록(종료 시간 - 시작 시간, 마이크로초)

    int sum3 = sum1 + sum2; // 컴파일러가 for문을 실행할 이유 만들기

    std::cout << "i -> j 순서로 접근(microsec)(순차 접근) = " << time1.count() << ", j -> i 순서로 접근(microsec)(도약 접근) = " << time2.count() << std::endl;

    return 0;
}