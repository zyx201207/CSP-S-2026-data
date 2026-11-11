#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=5e5+99;
ll n,m;
ll a[MAXN];
ll cnt[MAXN];
vector<ll> v;
void put(ll cur_card){
	ll s=n+1;
	for(int i=0;i<v.size();i++){
		if(v[i]==cur_card){
			s=i;
			break;		
		}
	}
	if(s==n+1){
		return;
	}
	ll q=n-s;
	while(q--){
		v.pop_back(); 
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int s=1;s<=n;s++){
		v.clear(); 
		for(int i=s;i<=n;i++){
			put(a[i]);
			v.push_back(a[i]);
		}
		for(int i=0;i<v.size();i++){
			cnt[v[i]]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
/*
4 3 1 2 1 3

*/ 
