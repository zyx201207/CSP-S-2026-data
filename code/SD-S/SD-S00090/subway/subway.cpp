#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,w[505],ans,sum,t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			t[i][x]=y;
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		scanf("%d%d",&x,&y);
		ans+=w[x]+w[y];
		printf("%d\n",ans);
    }
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
