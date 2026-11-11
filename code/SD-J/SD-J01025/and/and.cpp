#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const int N=200010;
ll a[N],p[61];
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0]=1;
	for (int i=1;i<=60;i++) p[i]=p[i-1]*2;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	ll ans=0;
	for (int z=30;z>=0;z--) {
		int num=0;
		for (int i=1;i<=n;i++) {
			if (a[i]&p[z]) num++;
		}
		if (num<m) continue;
		for (int i=1;i<=n;i++) {
			if (a[i]&p[z]) ;
			else a[i]=0;
		}
		ans+=p[z];
	}
	printf("%lld\n",ans);
	return 0;
}
/*
??:?? ~ 09:46
没B难(?
什么叫B题53min
C题7min
不对 我还要拍qwq 
对拍写10min
写对拍时间比写代码时间长是哪题 
*/
