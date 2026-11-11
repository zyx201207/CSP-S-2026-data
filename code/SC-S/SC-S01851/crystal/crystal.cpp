#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll  a[N];
ll  t[N];
ll n,m ;
ll mx=-1;
void dfs(int k){
	if(k >m)return;
	if(k==m){
		map<ll,ll>mp;
		for(int i=1;i<=n;i++){
			mp[t[i]]++;
		}
		for(int i=1;i<=n;i++){
			mx=max(mx,mp[i]);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		t[i]++;
		dfs(k+1);
		t[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
	}
	dfs(1);
	cout<<mx+1;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

*/