#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
ll m,a[500005],sum[500005];
bool ch(int x){
	for(int i=x;i<=n;i++)
		if(a[i]*1ll*(x-1)-sum[i-1]+sum[i-x]<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(ch(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
