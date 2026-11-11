#include<bits/stdc++.h>
using namespace std;
int n,m,q,tmp1,tmp2;
int w[501],k[501],a[501][1001],t[501][1001],g[1001][1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&tmp1,&n,&m,&tmp2,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
	    for(int j=1;j<=m;j++)
	        g[i][j]=1e9;
	for(int i=1;i<=m;i++)g[i][i]=0;
	for(int i=1;i<=n;i++){
	    scanf("%d",&k[i]);
	    for(int j=1;j<=k[i];j++)scanf("%d%d",&a[i][j],&t[i][j]);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k[i];j++)
            for(int x=1;x<j;x++)
                g[a[i][j]][a[i][x]]=g[a[i][x]][a[i][j]]=t[i][j]+t[i][x];
	for(int x=1;x<=m;x++)
	    for(int i=1;i<=m;i++)
	        for(int j=1;j<=m;j++)
	            g[i][j]=min(g[i][j],g[i][x]+g[x][j]);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&tmp1,&tmp2);
        printf("%d\n",w[tmp1]+w[tmp2]+g[tmp1][tmp2]);
    }
    return 0;
}

