#include <bits/stdc++.h>
int C,N,M,D,Q,w[500009];
long long d[509][509];
struct n_t{
	int a,v;
};std::vector<n_t> aq[500009];
signed main(void) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&C,&N,&M,&D,&Q);
	for(int i=1;i<=M;i++) {
		scanf("%d",&w[i]);
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=N;i++) {
		d[i][i]=0;
		int id;scanf("%d",&id);
		for(int j=1;j<=id;j++) {
			int p,t;
			scanf("%d %d",&p,&t);
			aq[p].push_back((n_t){i,t});
		}
	}
	for(int i=1;i<=M;i++) {
		for(int j=0;j<aq[i].size();j++) {
			for(int k=j+1;k<aq[i].size();k++) {
				d[aq[i][j].a][aq[i][k].a]=std::min(d[aq[i][j].a][aq[i][k].a],
					(long long)aq[i][j].v+aq[i][k].v);
			}
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			d[j][i]=std::min(d[j][i],d[i][j]);
		}
	}
	for(int k=1;k<=N;k++) {
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=Q;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		long long as=(0x3f3f3f3f3f3f3f3f);
		for(int j=0;j<aq[x].size();j++) {
			for(int k=0;k<aq[y].size();k++) {
				as=std::min(d[aq[x][j].a][aq[y][k].a]+aq[x][j].v+aq[y][k].v,as);
			}
		}
		as+=w[x]+w[y];
		printf("%lld\n",as);
	}
}
