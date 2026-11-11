#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N];
ll f[405][405];
vector<int> a[N],t[N],edge[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	memset(f,127,sizeof(f));
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			if(j>1){
				x=a[i][j-1],y=a[i][j-2];
				edge[x].push_back(y);
				edge[y].push_back(x);
			}
		}
		for(int j=0;j<k[i];j++)
			for(int l=0;l<k[i];l++){
				int x=a[i][j],y=a[i][l];
				f[x][y]=f[y][x]=t[i][j]+t[i][l];
			}
	}
	for(int l=1;l<=m;l++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(f[i][l]<1e9&&f[l][j]<1e9)
					f[i][j]=min(f[i][j],f[i][l]+f[l][j]);	
	for(;q--;){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",f[x][y]+w[x]+w[y]);
	}
	return 0;
}