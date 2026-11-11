#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans;
long long dj(int l,int r){return a[r]*(r-l+1)-sum[r]+sum[l-1];}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	long long r=0;
	for(int l=1;l<=n;++l){
		while(r<n&&dj(l,r+1)<=m)++r;
		ans=max(ans,r-l+1);
	}printf("%lld\n",ans);
}
