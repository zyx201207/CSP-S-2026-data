#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long sum[N],p[N],d,ans;
int nxt[N],cnt[N],lef[N],n;
int main(){
	freopen("migrate3.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int cid,T;scanf("%d %d",&cid,&T);
	while(T--){
		//zero();
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&p[i]);
		for(int l=n,r=n;l>=1;l--){
			while(p[r]-p[l]>d) r--;
			nxt[l]=r;cnt[l]=0;lef[l]=-1;
		}
		for(int i=n;i>=1;i++)
			cnt[i]=cnt[nxt[i]]+1;
		for(int i=n;i>=1;i++)
			cnt[i]+=cnt[i-1];
		for(int i=1;i<=n;i++){
			if(lef[i]==-1){
				lef[i]=0;int now=1,xi=i;
				while(nxt[xi]!=xi)
					lef[xi]=++now,xi=nxt[xi];
				lef[xi]=++now;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			int l=max(nxt[i]-1,nxt[nxt[i-2]]),
				r=min(nxt[i]-1,nxt[nxt[i-1]]);
			if(l<r) ans+=lef[i]*(cnt[r]-cnt[l-1]);
		}
		printf("%lld\n",ans);
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/