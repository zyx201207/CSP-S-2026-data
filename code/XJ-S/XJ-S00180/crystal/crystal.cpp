#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e6+10;
#define ll long long
int n;
ll m,a[N],pre[N];
bool check(int len){
	ll minn=1e18;
	//cout<<len<<'\n';
	for(int i=len;i<=n;i++){
		ll t=a[i]*(ll)(len)-(pre[i]-pre[i-len]);
		minn=min(minn,t);
		//cout<<t<<' '; 
	}
	//cout<<'\n';
	if(minn<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	int l=1,r=n;
	while(l<r-1){
		int mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
