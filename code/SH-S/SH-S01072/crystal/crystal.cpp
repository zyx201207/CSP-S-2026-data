#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,res;ll m;
ll a[500005],pr[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pr[i]=pr[i-1]+a[i];
	int l=1;
	for(int r=1;r<=n;r++){
		while(a[r]*(r-l+1)-pr[r]+pr[l-1]>m)l++;
		res=max(res,r-l+1);
	}
	printf("%d\n",res);
	return 0;
} 
