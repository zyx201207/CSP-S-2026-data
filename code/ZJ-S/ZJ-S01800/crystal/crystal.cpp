#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010]={},l=1e12,r=-1e12,ans=1,b[500010]={};
int calc(int w){
	for(int i=1;i<=n;i++) b[i]=abs(a[i]-w);
	sort(b+1,b+n+1);
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(sum+b[i]<=m) sum+=b[i],cnt++;
		else break;
	}
	return cnt;
}
bool f=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),l=min(l,a[i]),r=max(r,a[i]);
	for(int i=2;i<n;i++) a[i+1]-a[i]!=a[2]-a[1]?f=false:0;
	if(f){
		int cnt=1,sum=0;
		for(int i=2;i<=n;i++){
			if(sum+(a[2]-a[1])*(i-1)<=m) sum+=(a[2]-a[1])*(i-1),cnt++;
			else break;
		}
		printf("%lld",cnt);
		return 0;
	}
	for(int i=l;i<=r;i++) ans=max(ans,calc(i));
	printf("%lld",ans);
	return 0;
}
