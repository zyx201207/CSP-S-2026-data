//zhouyuanjie 陕西延安中学 SN-J00734 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a, num = 0, sum = 0;
	string b, c, d;
	cin >> n;
	for(long long i = 1; i <= n; ++i){
		cin >> a >> c;
		for(long long j = 1; j <= a; ++j){
			b += c;
		}
		num += a;
	}
	for(long long i = num - 1; i >= 0; --i){
		d += b[i];
	}
	for(long long i = 0, j = num; i < j; ++i, --j){
		if(d[i] == b[i]){
			continue;
		}
		else{
			d[i] = b[i];
			++sum;
		}
	}
	cout << sum;
	return 0;
}


