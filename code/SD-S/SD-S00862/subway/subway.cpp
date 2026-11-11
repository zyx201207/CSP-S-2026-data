#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int c,n,m,d,q;
int w[500005];
int k[505],a[505][500005],t[505][500005];

struct edge{
	int v,w,l;
};

vector<edge>g[500005];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
		
	if(c>=12&&c<=19){
		int T;
		for(int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%d%d",&a[i][j],&t[i][j]);
				T=t[i][j];
				if(j>0){
					int u=a[i][j-1],v=a[i][j],w=T,l=i;
					g[u].push_back((edge){v,w,l});
					g[v].push_back((edge){u,w,l});
				}
			}
		}
	}
	
	return 0;
}
