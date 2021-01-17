//sell[i]��ʾ��ֹ��i�죬���һ����������ʱ���������
//buy[i]��ʾ��ֹ��i�죬���һ����������ʱ���������
//cool[i]��ʾ��ֹ��i�죬���һ���������䶳��ʱ���������
//
//��̬ת�Ʒ��̣�
//sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);//�����ڵ�i������֮ǰ����Ĺ�Ʊ
//buy[i] = max(cool[i - 1] - prices[i], buy[i - 1]);//�����ڵ�i�������Ʊ
//cool[i] = max(cool[i - 1], sell[i - 1]);//�����ڵ�i����Ϊ�䶳��
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
		vector<int> sell(pricesSize, 0);//sell[i]��ʾ��ֹ��i�죬���һ����������ʱ���������
		vector<int> buy(pricesSize, 0);//buy[i]��ʾ��ֹ��i�죬���һ����������ʱ���������
		vector<int> cool(pricesSize, 0);//cool[i]��ʾ��ֹ��i�죬���һ���������䶳��ʱ���������
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
