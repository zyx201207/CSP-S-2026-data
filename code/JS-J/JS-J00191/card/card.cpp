#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
	ll n,m;cin>>n>>m;
	vector<ll> a(n+1),cnt(m+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cnt[i]+=cnt[i-1];
		cout<<cnt[i]<<' ';
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
