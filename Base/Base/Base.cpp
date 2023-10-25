#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
int main() {
	//求前n项的素数
	//注意：1不是素数，2是素数
	int n = 0;
	int num = 0;
	cout << "请输入范围:";
	scanf("%d", &n);
	clock_t startTime, endTime;
	startTime = clock();//计时开始
	int* nums = (int*)malloc((n + 1) * sizeof(int));	//下面算法将下标作为值比较
	//创建动态数组时默认不为0，所以要初始化为0
	for (int i = 0; i < n + 1; i++) {
		nums[i] = 0;
	}
	//从2开始，将数组下标是2倍数对应的值置为1
	//注意，这里是按数组下标的倍数进行对比，不是按数组里对应的值对比，例如第一次是nums[2]是2进行对比，不能理解为nums[2]作为第三项进行对比
	for (int i = 2; i < n + 1; i++) {
		//第一次 nums[2] == 0
		if (nums[i] == 0) {
			//将数组下标是2倍数对应的值置为1
			for (int j = i + i; j < n; j += i) {
				nums[j] = 1;
			}
		}
	}
	for (int i = 2; i < n + 1; i++) {
		if (nums[i] == 0) {
			num++;
		}
	}
	free(nums);
	cout << endl;
	cout << "num:" << num << endl;
	endTime = clock();//计时结束
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}