#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,l,r,ans=1,a[N],s[N];
int ch(int x){
	for(int i=1,j=x;j<=n;i++,j++)if(a[j]*x-s[j]+s[i-1]<=m)return 1;
	return 0;
}
#undef int
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#define int long long 
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(ch(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}