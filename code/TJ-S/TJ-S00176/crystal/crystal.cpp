#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long n,m;
    long long a[50005];
    long long temp1 = 0; //平均数

    cin >> n >> m;

    for (int i = 0;i < n;i++) {
    	cin >> a[i];
    	temp1 += a[i];
	}

    temp1 = temp1 / n;

    //find the mid num in real number set;

    long long a1[50005]; //记录每项和平均数的差的绝对值

    for (int i = 0;i < n;i++) {
    	a1[i] = temp1 - a[i]; //计算差
    	if (a1[i] < 0) {
    		a1[i] = a1[i] * -1; //绝对值
		}
	}

	int temp3 = 0; //当前a1数组中最小的数
	int temp4 = 0; //它在a1,a数组中的位置

	/* for (int i = 0;i < n ;i++) { //找最小 cundang 1
		temp3 = a1[i];
		temp4 = i;
		if (temp3 > a1[i-1]) {
			temp3 = a1[i-1];
			temp4 = i-1;
		}
	}

	*/

	for (int i = 1;i < n ;i++) { //找最小
		temp3 = a1[i];
		temp4 = i;
		if (temp3 >= a1[i-1]) {
			temp3 = a1[i-1];
			temp4 = i-2;
		}
	}

	int cnt = 0; //相同的数
	for (int i = 0;i < n ;i++) { //找相同
		if (a[i] == a[temp4]) cnt++;
	}

	int a2[500005]; //排序过的a数组
	for (int i = 0; i < n;i++) {
		a2[i] = a[i];

		a1[i] = 0; //初始化a1数组

	}

	sort(a2,a2+n); // 排序

	int temp5; //a2中的temp4位置

	for (int i = 0;i < n;i++) {
		if (a2[i] == a[temp4]) {
			temp5 = i;
			break;
		}
	}

	int sum = 0;//水晶个数
	int temp6 = 0;

	for (int k = 0;k < temp5;k++)  {//记得回来看这里 okay no problem now

		for (int j = 0;j < temp5;j++) {
			a1[j] = a[temp4] - a2[j]; //算差
	}

		temp6 += a1[k]; //和

	}

	if (temp6 == m) {
		sum = temp5 - 1;
	}


    cout << cnt + temp5 << endl;

    return 0;
}
