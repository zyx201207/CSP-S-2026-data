#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<ll> num;
map<ll,ll> vis;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		num.push_back(x);
		vis[x]++;
	}
	ll sum=0;
	for(int i=0;i<=10;i++){
		if(vis[i]>1){
			sum=max(sum,vis[i]);
		}
	}
	if(sum==0&&m==0){
		cout<<0;
		return 0;
	}else if(sum!=0&&m==0){
		cout<<sum;
		return 0;
	}
	ll mi=0,ma=1,o=1;
	while(true){
		if(m>=mi&&m<ma){
			cout<<o;
			break;
		}
		mi=mi+o;
		ma=mi+o+1;
		o++;
	}
	return 0;
} 
