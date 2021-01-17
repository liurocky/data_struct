/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline.
It is also given that every job takes the single unit of time, 
so the minimum possible deadline for any job is 1. 
How to maximize total profit if only one job can be scheduled at a time.

Examples:

Input: Four Jobs with following
deadlines and profits
JobID  Deadline  Profit
  a      4        20
  b      1        10
  c      1        40
  d      1        30
Output: Following is maximum
profit sequence of jobs
        c, a


Input:  Five Jobs with following
deadlines and profits
JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15
Output: Following is maximum
profit sequence of jobs
        c, a, e
*/

#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id[32];
    int  deadLine;
    int profit;

    Job(const char* sid, int dl, int p) {
        strcpy(id, sid);
        deadLine = dl;
        profit = p;
    }
};

bool profit_cmp(const Job& lhs, const Job& rhs) {
    
    if (lhs.deadLine < rhs.deadLine) {
        return true;
    }
    else if (lhs.deadLine == rhs.deadLine) {
        return lhs.profit <= rhs.profit;
    }
    return false;
}

int main(int argc, char** argv) {
    vector<Job> job_vec;
    job_vec.push_back(Job("a", 4, 20));
    job_vec.push_back(Job("b", 1, 10));
    job_vec.push_back(Job("c", 1, 40));
    job_vec.push_back(Job("d", 1, 30));
    std::sort(job_vec.begin(), job_vec.end(), profit_cmp)
        ;
}