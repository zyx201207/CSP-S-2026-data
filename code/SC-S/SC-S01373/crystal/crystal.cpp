#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=514514;
ll a[maxn],res=0,m;
int q[maxn],ans=-1,n;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=0;
	q[++r]=1;
	for(int i=2;i<=n;i++){
		ll k=(a[i]-a[i-1])*(q[r]-q[l]+1);
		while(l<=r && res+k>m) res-=a[i]-a[q[l]],l++;
		q[++r]=i;res+=k;
		ans=max(ans,q[r]-q[l]+1);
	}
	printf("%d\n",ans);
}
/*
5 8
-3 -1 2 2 7
*/