#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],b[500005];
ll pre[500005];
bool cmp(ll c,ll d){
	return c>d;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1]+a[i];
	}
	ll l = 1;
	ll maxx = 0;
	for(int r=2;r<=n;r++){
		while(a[r]*(r-l+1)-(pre[r]-pre[l-1])>m and l<r){
			l++;
		}
		if(l!=r){
			maxx = max(maxx,r-l+1);
		}
	}
	cout<<maxx;
	return 0;
}
