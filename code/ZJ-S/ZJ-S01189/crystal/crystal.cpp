#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 500001
int n,m;
int a[maxn];
int qz[maxn];
int ans=0;
void procedure(int x){
	int l=1,r=x,res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(qz[x]-qz[mid-1])<=m)res=mid,r=mid-1;
		else l=mid+1;
	}
	ans=max(ans,x-res+1);
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	qz[0]=0;for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i];
	for(int i=1;i<=n;i++)procedure(i);
	printf("%lld\n",ans);
	return 0;
}