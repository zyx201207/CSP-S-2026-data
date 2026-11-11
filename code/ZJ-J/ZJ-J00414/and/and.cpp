#include<bits/stdc++.h>
using namespace std;
long long n,m,a,maxn = -1,cnt = 0;
int bits[200010][33],zj[200010];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a;
		long long j = 256 * 256 * 256 * 64;
		for(int k = 30;k >= 1;k--){
			j /= 2;
			if(a >= j){
				bits[i][k] = 1;
				a -= j;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int k = 30;k >= 1;k--){
			cout << bits[i][k];
		}
		cout << endl;
	}
	int jieguo_bits[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int wb = 1;wb <= 30;wb++){
		for(int i = 1;i <= n;i++){
			if(bits[i][wb] == 1)jieguo_bits[wb]++;
		}
	}
	for(int i = 30;i >= 1;i--){
	    cout << jieguo_bits[i];
	}
	cout << endl;
	for(int i = 30;i >= 1;i--){
	    if(jieguo_bits[i] >= m)cnt += (pow(2,i) / 2);
	}
	cout << endl;
	cout << cnt;
	return 0;
}