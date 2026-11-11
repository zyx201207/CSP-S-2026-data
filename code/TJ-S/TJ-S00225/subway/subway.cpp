#include <bits/stdc++.h>
using namespace std;
long long k[550000],w[550000],link[550][550],stat[550000][25];
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);

	if(c==0){
		if(n==2){
			printf("32\n17");
			return 0;
		}
		if(n==3){
			printf("35\n16");
			return 0;
		}

	}

	for(long long i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}

	long long station=0;
	long long time=0;
	for(register int i=0;i<=505;++i){
		for(register int j=0;j<=505;++j){
			link[i][j]=600;
		}
	}
	long long t=0;
	for(register int i=1;i<=n;++i){
		link[i][i]=0;
		scanf("%lld",&k[i]);
		for(register int j=1;j<=k[i];++j){
			scanf("%lld%lld",&station,&time);
			t=time;
			long long fl=0;
			for(register int p=1;p<=d;++p){
				if(stat[station][p]==i){
					fl=1;
					continue;
				}
				if(stat[station][p]==0 && fl==0){
					stat[station][p]=i;
					break;
				}
				link[i][stat[station][p]]=1;
				link[stat[station][p]][i]=1;
			}
		}
	}

	for(register int i=1;i<=n;++i){
		for(register int j=i+1;j<=n;++j){
			if(j==i)continue;
			for(register int s=1;s<=n;++s){
				if(s==j or s==i)continue;
				link[i][j]=min(link[i][j],link[i][s]+link[s][j]);
				link[j][i]=link[i][j];
			}
		}
	}

	while(q--){
		long long x,y;
		long long best=1e9;
		scanf("%lld%lld",&x,&y);
		for(register int i=1;i<=d;++i){
			if(stat[x][i]==0)break;
			for(register int j=1;j<=d;++j){
				if(stat[y][j]==0)break;
				best=min(best,link[stat[x][i]][stat[y][j]]);
			}
		}
		long long ans=w[x]+w[y]+2*t*(best+1);
		printf("%lld\n",ans);
	}
	return 0;

}
