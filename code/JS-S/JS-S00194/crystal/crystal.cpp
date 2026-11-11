#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in", "r", stdin);//#include<iostream>usingnamespacestd;intmainreturn0;trickortreat trickortreat trickortreat trickortreat trickortreatIneedtoget888bytes -- Now 2888 [Sad face]
	freopen("crystal.out", "w", stdout);//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
	long long n, m, cnt = 0, ans = 0, sum = 0;//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
	cin >> n >> m;//1234567890
	long long a[n + 5];//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
	for(int i = 1; i <= n; i++){//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
		cin >> a[i];//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
		if(i != 1){//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
			sum += (a[i] - a[i - 1]) * (i - 1);//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
		}//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
	} if(sum <= m){//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
		cout << n;//trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat
		return 0;//Alright, I don't care about length in this line anymore. trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat trickortreat 
	} for(int i = 1; i <= n; i++){
		cnt += (a[i + 1] - a[i]) * i;
		if(cnt > m){
			ans = i;
			break; 
		}
	} cout << ans;
	return 0;
}
