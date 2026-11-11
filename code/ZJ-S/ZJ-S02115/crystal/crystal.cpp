#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],i,j=0,sy=0,gs=0,ans;
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(i=1;i<n;i++){
		gs++;
		sy+=(a[i]-a[i-1])*gs;
		if(sy>m){
			ans=max(gs,ans);
			gs--;
			sy-=a[i]-a[j];
			j++;
		}
	}
	ans=max(gs,ans);
	printf("%lld\n",ans);
	return 0;
}

