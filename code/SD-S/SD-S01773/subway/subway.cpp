#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[550000],l[550000],ds[1100][1100];
struct asd{
	long long t,n;
}s[500050][22];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			ds[i][j]=1e18;
		}
	}
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long a,t;
			scanf("%lld%lld",&a,&t);
			l[a]++;
			s[a][l[a]].t=t;
			s[a][l[a]].n=i;
//			ds[]
		}
	}
	for(long long k=1;k<=m;k++){
		for(long long i=2;i<=l[k];i++){
			for(long long j=1;j<i;j++){
				long long ii=s[k][i].n,jj=s[k][j].n;
				ds[ii][jj]=ds[jj][ii]=min(ds[ii][jj],s[k][i].t+s[k][j].t);
			}
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			if(i==k){
				continue;
			}
			for(long long j=1;j<i;j++){
				if(j==k){
					continue;
				}
				ds[i][j]=ds[j][i]=min(ds[i][j],ds[i][k]+ds[k][j]);
			}
		}
	}
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++){
//			printf("%lld %lld: %lld\n",i,j,ds[i][j]);
//		}
//	}
	while(q--){
		long long x,y,p=1e18;
		scanf("%lld%lld",&x,&y);
		for(long long i=1;i<=l[x];i++){
			for(long long j=1;j<=l[y];j++){
				p=min(p,ds[s[x][i].n][s[y][j].n]+s[x][i].t+s[y][j].t);
			}
		}
		printf("%lld\n",p+w[x]+w[y]);
	}
	return 0;
}
