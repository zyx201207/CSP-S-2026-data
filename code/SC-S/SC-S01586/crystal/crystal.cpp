#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005],ans,nd[1000005],gs[1000005],bj[1000005];
void sx(long long x,long long l,long long pd){
	long long zd=0,flog=0;
	if(l<=m){
		for(long long z=1;z<=n;z++) bj[z]=0;
		return;
	}
	for(long long i=1;i<=n;i++){
		if(i==pd||bj[i]==1) continue;
		if(a[i]<x&&x-a[i]>zd) zd=x-a[i],flog=i;
	}
	bj[flog]=1;
	gs[pd]--;
	sx(x,l-zd,pd);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++) if(a[j]<=a[i]) nd[i]+=a[i]-a[j],gs[i]++;
		if(nd[i]>m) sx(a[i],nd[i],i);
		if(gs[i]>ans) ans=gs[i];
	}
	cout<<ans;
	return 0;
}
