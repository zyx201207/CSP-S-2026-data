#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > v(5005);
int c,n,m,d,q,w[500005],T,pos[5005][5005],ma[5005][5005];
int main()
{
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
			int x,y;
			scanf("%d%d",&x,&y);
			T=y;
			v[i].push_back(make_pair(x,y));
			ma[i][x]=y;
			pos[i][x]=1;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int gw=-1;
		for(int j=1;j<=n;j++){
			if(pos[j][x]==1 && pos[j][y]==1){
				gw=j;
			}
		}
		if(gw==-1)printf("%d\n",(2*n-1)*T+w[x]+w[y]);
		else{
			printf("%d\n",ma[gw][x]+ma[gw][y]+w[x]+w[y]);
		}
	}
	
	return 0;
}
