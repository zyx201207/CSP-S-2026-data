#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500000+10;
int n,ans=0;
ll m,a[maxn],s[maxn];
int erfen(int l,int r,int pos){
	while(l<r){
		int mid=(l+r)>>1;
		if(a[pos]*(pos-mid+1)-(s[pos]-s[mid-1])<=m) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int t=erfen(1,i,i);
		ans=max(ans,i-t+1);
	}
	printf("%d\n",ans);
	return 0;
}