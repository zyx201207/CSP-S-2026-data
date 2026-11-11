#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500005
#define inf 1e18
int n;
ll m,a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int r=1,ans=1;ll cost=0,d=a[1];
	for(int l=1;l<=n;l++){
		while(cost<=m){
			r++;
			if(r==n+1)break;
			cost+=(a[r]-d)*(r-l);
			d=a[r];
		}
		if(r==n+1)break;
		ans=max(ans,r-l);
		cost-=d-a[l];
	}
	printf("%d",ans);
	return 0;
}
