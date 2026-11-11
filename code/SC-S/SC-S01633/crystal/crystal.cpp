#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;
ll maxn=1;
ll a[N],m,pre[N];
ll sum(ll l,ll r){
	return a[r]*(r-l+1)-(pre[r]-pre[l-1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	ll l=1,r=1;
	while(r<=n){
		maxn=max(maxn,(r-l+1));
		if(sum(l,r)<=m&&sum(l,r+1)<=m)r++;
		else if(l+1<=r)l++;
		else r++;
	}
	cout<<maxn;
	return 0;
} 