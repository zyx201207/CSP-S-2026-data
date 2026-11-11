#include<iostream>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5+10;
int n;
ll m,maxn,ans = 1;
ll a[MAXN];
void check(ll pos){
	ll sum = 1; 
	ll t = a[pos];
	ll tm = m;
	for(int i = pos-1;i>=1;i--){
		ll bu = t - a[i];
		if(tm < bu)break;
		sum ++;
		tm -= bu;
	}
	ans = max(ans,sum);
	//cout<<pos<<' '<<ans<<'\n';
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n <= 5000){
		for(int i=2;i<=n;i++){
			check(i);
		}
		cout<<ans;
	}
	else{
		ll cha = a[2] - a[1];
		ll l = a[1];
		ll ptr = 1;
		while(((a[ptr+1] - l)/cha + 1) <= ceil((2*m)*1.0/((l+a[ptr+1])-1)) && ptr+1 <= n)ptr ++;
		//cout<<ptr<<' '<<((a[ptr] - l)/cha + 1)<<' '<<((2*m)/(l+a[ptr]))<<'\n';
		ll r = a[ptr];
		ans = ((r - l)/cha + 1);
		cout<<ans;
	}
	return 0;
} 

/*
8 70
1 5 9 13 17 21 25 29
*/