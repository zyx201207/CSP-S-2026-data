#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p,T;
int a[500010];
long long t[500100];
bool cf[500010][30];
vector <int> w[500100];
long long dist[200101];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(cf,0,sizeof(cf));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for ( int i=1; i<=m; i++ ) {
		scanf("%lld",&t[i]);
	}
	for ( int i=1; i<=n; i++ ) {
		int l=0;
		scanf("%d",&l);
		int q[50010];
		for ( int j=1; j<=l; j++ ) {
			int x,y;
			scanf("%d%d",&x,&y);
			q[j]=x,T=y;
		}
		for ( int j=1; j<=l; j++ ) {
			for ( int k=j+1; k<=l; k++ ) {
				if ( !cf[q[j]][q[k]]) {
					w[q[j]].push_back(q[k]);
					w[q[k]].push_back(q[j]);
					cf[q[j]][q[k]]=1,cf[q[k]][q[j]]=1;
				}
			}
		}
	} printf("%d\n",T);
	for ( int i=1; i<=p; i++ ) {
		int x,y;
		scanf("%d%d",&x,&y);
		int l=0,r=0;
		vector <int> qp;
		vector <int> qp2;
		memset(dist,255,sizeof(dist));
		qp.push_back(x);
		qp2.push_back(0);
		dist[x]=0;
		while ( l<=r ) {
			int k=qp[l];
			for ( int v=0; v<w[k].size(); v++ ) {
				int len=w[k][v];
				if ( dist[len]!=-1 ) 
					continue ;
				dist[len]=dist[k]+1;
				if ( qp2[k]!=0&&!cf[qp2[k]][len]) dist[len]+=1;
				qp.push_back(len);
				qp2.push_back(k);
				//printf("%d %d \n",len,dist[len]);
				r++;
			} l++;
		}
		printf("%lld\n",dist[y]*T+t[x]+t[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 2 2 2 4 2
3 2 2 3 2 5 2
1 5
1 2
*/
