#include<bits/stdc++.h>
using namespace std;
int a_n[200001];
int a_m[200001];
int a[200001];
int ad_y(int a,int b){
	int a_jz[200001];
	int b_jz[200001];
	int c_jz[200001];
	int k,bl = b,al = a;
	if(a > b){
		k = a;
	}else k = b;
	for(int i =1;i <= al/2;i++){
		if(a <= 0) break;
		if(a % 2 == 1){
			a_jz[i] = 1;
		}else a_jz[i] = 0;
	}
	for(int i = 1;i <= bl/2;i++){
		if(b <= 0) break;
		if(b % 2 == 1){
			b_jz[i] = 1;
		}else b_jz[i] = 0;
	}
	int ans = 0;
	for(int i = 0;i <= k;i++){
		if(a_jz[i+1] == b_jz[i+1]){
			c_jz[i] = 1;
		}else c_jz[i] = 0;
		ans += c_jz[k-i-1] * pow(1,i-1);
	}
	return ans;
}
bool cop(int a,int b){
	if(a != b) return a > b;
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a_n[i];
	}
	for(int i = 2;i <= n;i++){
		a_m[i-1] = ad_y(a_n[i],a_n[i-1]);
	}
	sort(a_m+1,a_m+n+1,cop);
	cout << a_m[1];
	return 0;
}
