// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

float count_degree(double flng1, double flat1, double tlng1, double tlat1,
    double flng2, double flat2, double tlng2, double tlat2)
{
    double length = ((tlat1 - flat1) * (tlat1 - flat1) + (tlng1 - flng1) * (tlng1 - flng1)) * ((tlat2 - flat2) * (tlat2 - flat2) + (tlng2 - flng2) * (tlng2 - flng2));
    double scalar = (tlat1 - flat1) * (tlat2 - flat2) + (tlng1 - flng1) * (tlng2 - flng2);
    //订单长度很短
    if (length < 0.0000000001) return 180.0;
    //余弦值异常情况
    double valuecos = scalar / sqrt(length);
    if (valuecos > 0.99999) valuecos = 0.99999;
    if (valuecos < -0.99999) valuecos = -0.99999;

    return acos(valuecos) * 57.2957795;
}



struct TripFeature {
    int64_t	 order_list[10];
    int order_cnt;

    TripFeature() {
        memset(this, 0, sizeof(*this));
    }
};

vector<TripFeature>& CombinePack(int n, int k, vector< TripFeature >& res, bool only_new) {
    if (k > n || n == 0) return res;
    TripFeature trip;
    trip.order_cnt = k;
    int i = 0;
    while (i >= 0) {
        ++trip.order_list[i];
        if (trip.order_list[i] > n) {
            --i;
        }
        else if (i == k - 1) {
            if (trip.order_list[k - 1] == n || !only_new) {
                res.push_back(trip);
            }
        }
        else {
            ++i;
            trip.order_list[i] = trip.order_list[i - 1];
        }
    }
    return res;
}


#include <algorithm>

int NextPermutation(int* begin, int* end)
{
    int* i = begin, * j, * k;
    if (i == end || ++i == end) return 0;   // 0 or 1 element, no next permutation
    for (i = end - 1; i != begin;) {
        j = i--;    // find last increasing pair (i,j)
        if (!(*i < *j)) continue;
        // find last k which not less than i,
        for (k = end; !(*i < *(--k)););
        iter_swap(i, k);
        // now the range [j,end) is in descending order
        reverse(j, end);
        return 1;
    }
    // current is in descending order
    reverse(begin, end);
    return 0;
}

bool is_even(int i) {
    return (i & 0x1) == 0;
}

#include <Windows.h>

#define MAX_TRIP_SIZE 16

#define FILTER_OD_REVERSE 101
#define FILTER_ON_OFF_REVERSE 102 

bool is_filter(const std::vector<int>& v) {
    int flag[MAX_TRIP_SIZE] = {0};
    int find_off = 0;
    for (int i = 0; i < v.size(); i++) {
        if (is_even(v[i])) {
            if(flag[v[i] / 2]) return FILTER_OD_REVERSE;
            if (find_off) return FILTER_ON_OFF_REVERSE;
        }
        else {
            flag[v[i] / 2]++;
            find_off = 1;
        }
    }
    return 0;
}

int GetPathPermutation(int n, vector< vector<int> >& path_vec) {
    vector<int> v;
    for (int i = 0; i < 2 * n; i++) {
        v.push_back(i);
    }
    do {
        if ( !is_even(v.front()) || is_even(v.back()) || is_filter(v)) continue;
        else path_vec.push_back(v);
    } while (std::next_permutation(v.begin(), v.end()));
    return path_vec.size();
}


// N+1
int GetPathNPlus1(const vector<int>& in_order_sort, int to_do) {

}

int GetPath2Opt() {

}

int Greedy() {

}

int Branch() {
    
}


class VRPStrategy {
public:

};

#include <unordered_map>
#include <string>

struct ODMapInfo {
    int dist;
    int eta;
    vector<int> links;
    vector<int> xys;
};

class VRPHandle {
    std::unordered_map<std::string, ODMapInfo> od_map;
public:
     
};


inline float count_degree2(double flng1, double flat1, double tlng1, double tlat1,
    double flng2, double flat2, double tlng2, double tlat2)
{
    double length = ((tlat1 - flat1) * (tlat1 - flat1) + (tlng1 - flng1) * (tlng1 - flng1)) * ((tlat2 - flat2) * (tlat2 - flat2) + (tlng2 - flng2) * (tlng2 - flng2));
    double scalar = (tlat1 - flat1) * (tlat2 - flat2) + (tlng1 - flng1) * (tlng2 - flng2);
    //订单长度很短
    if (length < 0.0000000001) return 180.0;
    //余弦值异常情况
    double valuecos = scalar / sqrt(length);
    if (valuecos > 0.99999) valuecos = 0.99999;
    if (valuecos < -0.99999) valuecos = -0.99999;

    return acos(valuecos) * 57.2957795;
}


struct A {
    int a;
    char b;

    A() {
        memset(this,0,sizeof(*this));
    }
};

struct TimeSlot {
    
};


#include <boost/lexical_cast.hpp>

int main(),,,/,//
{
    char buf[] = { '1', '2', '3', '\0', '4', '5', '6' };
    string s(buf);
    cout << s << endl;
    string s1(buf, sizeof(buf));
    cout << sizeof(buf) << "\t" << s1 << endl;
    cout << boost::lexical_cast<buf> << endl;

    cout << count_degree2(118.074097, 24.462509, 118.147408, 24.542860, 118.147408, 24.542860, 117.687012, 24.501129) << endl;
    int n = 4;
  
    DWORD T0 = GetTickCount();
    vector< vector<int> > path_vec;
    path_vec.resize(30000);
    for (int iter = 0; iter < 100000; iter++) {
        path_vec.clear();
        GetPathPermutation(n, path_vec);
        if (iter % 1000 == 0) cout << path_vec.size() << '\n'; 
    }
    DWORD T1 = GetTickCount();
    cout << (T1 - T0) /10000 << endl;
    return 0;


 /*   vector<TripFeature> res;
    CombinePack(4, 3, res, true);

    float a = count_degree(24.463270, 118.080116, 24.471240, 118.098230, 24.471240, 118.098230, 24.506453, 117.659540);
    cout << a << endl;
    float b = count_degree(24.491850, 118.127650, 24.471240, 118.098230, 24.471240, 118.098230, 24.506453, 117.659540);
    cout << b << endl;

    float c = count_degree(24.491850, 118.127650, 24.491850, 118.227650, 24.491850, 118.127650, 24.391850, 118.127650);
    cout << c << endl;
    float d = count_degree(24.491850, 118.127650, 24.491850, 118.227650,
                           24.491850, 118.127650, 24.591850, 118.127650);
    cout << c << endl;
    std::cout << "Hello World!\n";*/
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
