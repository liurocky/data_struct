#include <iostream>
using namespace std;

int fib(int n)  {
    if (n <= 1) return n;
    else  return fib(n - 1) + fib(n - 2);
}

int look_up[41] = { 0 };

int fib2(int n) {
    if (n <= 1) return n;
    else if (look_up[n]) return look_up[n];
    else {
     look_up[n]= fib(n - 1) + fib(n - 2);
     return look_up[n];
    }
}

/*
b) Tabulation (Bottom Up): The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table.
For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on. So literally,
we are building the solutions of subproblems bottom-up.
Following is the tabulated version for nth Fibonacci Number.
*/
#include<stdio.h> 
const int N = 100;
int fib3(int n)
{
    int f[N + 1];
    int i;
    f[0] = 0;   f[1] = 1;
    for (i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n];
}

#include <Windows.h>
int main(int argc, char** argv) {

    DWORD t0 =  ::GetTickCount();
    cout << fib(40) << endl;
    DWORD t1 = ::GetTickCount();
    cout << fib2(40) << endl;
    DWORD t2 = ::GetTickCount();
    cout << fib3(40) << endl;
    DWORD t3 = ::GetTickCount();
    cout << t1 - t0 << "||" << t2 - t1  << "||" << t3-t2 << endl;
    return 0;
}