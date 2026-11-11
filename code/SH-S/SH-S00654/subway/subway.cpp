#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1505;
const ll INF=199999999;
int c,n,m,d,q;
ll w[N];
int cnt;
ll floyd[2000][2000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=1700;i++){
		for(int j=1;j<=1700;j++){
			floyd[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		cnt++;
		for(int j=1;j<=k;j++){
			int v,l;
			scanf("%d%d",&v,&l);
			floyd[cnt][v]=l;
			floyd[v][cnt]=l;
		}
	}
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<=cnt;i++){
			if(floyd[i][k]!=INF)
			for(int j=i+1;j<=cnt;j++){
				if(floyd[k][j]!=INF)
				floyd[j][i]=floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",floyd[x][y]+w[x]+w[y]);
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2


