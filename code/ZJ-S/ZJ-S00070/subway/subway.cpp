#include<bits/stdc++.h>
using namespace std;

struct node{
	int to,w;
};
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005];
vector<node> edges[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
		for(int j=1;j<=k[i];j++){
			for(int jj=1;jj<=k[i];jj++){
				if(j==jj)
					continue;
				edges[j].push_back({jj,t[i][j]+t[i][jj]});
				edges[jj].push_back({j,t[i][j]+t[i][jj]});
			}
		}
	}
	for(;q--;){
		int x,y;
		scanf("%d%d",&x,&y);
		
	}
	return 0;
}