//sell[i]表示截止第i天，最后一个操作是卖时的最大收益
//buy[i]表示截止第i天，最后一个操作是买时的最大收益
//cool[i]表示截止第i天，最后一个操作是冷冻期时的最大收益
//
//动态转移方程：
//sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);//尝试在第i天卖出之前买入的股票
//buy[i] = max(cool[i - 1] - prices[i], buy[i - 1]);//尝试在第i天买入股票
//cool[i] = max(cool[i - 1], sell[i - 1]);//尝试在第i天作为冷冻期
//1
//2
//3
//4
//5
//6
//7
//8https://bpm.didichuxing.com/task/form/3639cace-4f35-11eb-b501-346ac2b62bec
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int pricesSize = prices.size();
		if (pricesSize == 0) {
			return 0;
		}
		vector<int> sell(pricesSize, 0);//sell[i]表示截止第i天，最后一个操作是卖时的最大收益
		vector<int> buy(pricesSize, 0);//buy[i]表示截止第i天，最后一个操作是买时的最大收益
		vector<int> cool(pricesSize, 0);//cool[i]表示截止第i天，最后一个操作是冷冻期时的最大收益
		buy[0] = -prices[0];
		for (int i = 1; i < pricesSize; ++i) {
			sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
			buy[i] = max(cool[i - 1] - prices[i], buy[i - 1]);
			cool[i] = max(cool[i - 1], sell[i - 1]);
		}
		return sell[pricesSize - 1];
	}
};



#include "Class.h"

int main(int argc, char** argv) {

	vector<int> prices = {1,2,3,0,2};
	Solution sol;
	int ret = sol.maxProfit(prices);
	cout << ret << endl;
	return 0;
}
