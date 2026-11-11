#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N],lst[N],f[N],g[N];
unordered_map<int,int> ct;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while (t--) {
		long long ans=0;x[0]=-4e18;
		scanf("%lld%lld",&n,&d);
		for (int i=1; i<=n; i++) {
			scanf("%lld",x+i);
			int ls=lst[i-1];
			while (x[i]-x[ls]>d) ls++;
			lst[i]=ls;
//			cerr<<"LST "<<lst[i]<<endl;
		}
		if (false && c<=10 || c>12) for (int i=1; i<=n; i++) {
			//start from i
			f[i]=0,g[i]=1,ct.clear(),ct[0]=1;
			for (int j=i+1,k=i; j<=n; j++) {
				while (x[j]-x[k]>d) ct[f[k]]-=g[k],k++;
				int ls=max(lst[j],i);
				if (ls==j) break;
				f[j]=f[ls]+1;
				g[j]=ct[f[ls]];
				ct[f[j]]+=g[j];
//				cerr<<"CCCCCCC "<<f[j]<<' '<<g[j]<<endl;
//				if (g[j]>2) break;
				if (g[j]==2) ans++;
			}
		}else if (c<=12) {
			int tc=d/(x[2]-x[1]),hf=tc-1;//mod tc ºÏ·¨ÓàÊý
			if (!tc) ans=0;
			else for (int i=1; i<=n; i++) {
				int nn=n-i+1;
				int ddvv=nn/tc;
				if (ddvv*tc+hf==nn) ans++;
				ans+=ddvv; 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
how to get [l,r]'s min?
let f[i]= r=i,how much ans
then how much l?
we only need to count the islands with 1 or 2 routes.
yep,we count the 1 or 2 route islands.
how to DP? we need to find minimum route first.
what time will it have 3+ routes?
if i have 3+ routes,then i++ have more than 3+ routes.
is it true?maybe it is!!!
this is a very good thing.
so we can binary search the point that >=3.
we find 1,r,the r is a segment.
then about l++.when l +1,what will r do?
idk,but lets meiju l and binary the r.
...cant do it.
n=5000 can do.
when is 1?when is 2?
no...only n=5000 40pts
I hate it!!!!!!!!
..wait,it's dandiao.
it cant ka me
this is fast.
if u random u will DIE!
*/
