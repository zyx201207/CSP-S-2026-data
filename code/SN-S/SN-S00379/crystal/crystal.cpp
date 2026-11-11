//zhouyuanjie 陕西延安中学 SN-S00379
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, sum, num, len;
	long long a, b[10000000005];
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a;
		b[i] = a;
		++num;
	}
	int c = b[1] - b[0];
	len = (b[num] - b[0]) / c + 1;
	sum = (b[0] + b[num]) * len / 2;
	cout << sum;
	
	return 0;
}
