#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a, bin[35], sho, all[200010];//bin:n个数中，第i位有多少个数为1  
bool ans[200010];//存二进制，便于还原 all:检查之前是否有相同的数
vector<ll> v[35], num;//v:n个数中，第i位为1的数 num:大于m的数位 
void back(){
	ll f=1, ret=0;
	for(ll i=0;i<=30;i++){
		if(ans[i]) ret+=f;
		f*=2;
	}
	cout<<ret;
	return;
}
void push(ll x){
	ll f=0, _x=x;
	while(x){
		if(x&1){
			bin[f]++;
			v[f].push_back(_x);
		}
		f++;
		x>>=1;
	}
	return; 
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a;
		push(a);
	}
	for(ll i=30;i>=0;i--){
		if(bin[i]>=m) num.push_back(i);
	}
	for(ll i=num.size()-1;i>=0;i--){
		ll now=0;
		vector<ll> leg;
		for(ll j=0;j<bin[num[i]];j++){
			if(all[v[i][j]]==sho){
				now++;
				leg.push_back(v[i][j]);
			}
		}
		if(now>m) ans[num[i]]=1;
		else if(now==m){
			ll ret=leg[0];
			for(ll j=1;j<leg.size();j++) ret&=leg[j];
			cout<<ret;return 0;
		}else continue;
		for(ll j=0;j<bin[num[i]];j++){
			if(all[v[i][j]]==sho) all[v[i][j]]++;
		}
		sho++;
	}
	back();
	return 0;
} 
