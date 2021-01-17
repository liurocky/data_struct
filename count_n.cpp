#include <iostream>
using namespace std;

int CountN(int N) {
    
    // 3  1*1+2   1*2+1 2*1 + 1 
    // 

    if (N == 3) {
        int test = 0;
    }
    int d = 0;
    for (int i = 1; i < N; i++) {
        int mj = N / i;
        for (int j = 1; j <= mj; j++) {
            int k = N - i * j;
            if(k)   d++;
        }
    }

    return  d;
}

int main(int argc, char** argv) {
    for(int i = 1; i < 10; i++)  cout << i << "  " << CountN(i) << endl;
    cout << 100 << "  " << CountN(100) << endl;
}