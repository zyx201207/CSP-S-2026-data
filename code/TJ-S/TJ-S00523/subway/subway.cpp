#include <bits/stdc++.h>
using namespace std;
const int N=540,M=5e5+10;
int g[N][N];
int c,n,m,d,q;
struct Station{
	int a,t;
};
struct Stop{
	int car[24];
	int t[24];
	int idx; 
};
//vector<Station> sta[N];
Stop sto[M];
inline void add(int a,int b,int c){
	g[a][b]=min(g[a][b],c);
}
int w[M];
int main(){//999,600,000?
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof g);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		g[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int a,t;
			scanf("%d %d",&a,&t);
			Stop &s=sto[a];
			s.car[s.idx]=i;
			s.t[s.idx++]=t;
			//sta[i].push_back({a,t}); 
		}
	}
	for(int i=1;i<=m;i++){
		int l=sto[i].idx;
		for(int j=0;j<l;j++){
			int w=sto[i].t[j];
			for(int k=0;k<l;k++){
				add(sto[i].car[j],sto[i].car[k],w+sto[i].t[k]);
//				cout << j << " " << k << " " <<  w+sto[i].t[k] << endl;
			}
		}
	}
//	}for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			if(g[i][j]!=0x3f3f3f3f)
//				cout << g[i][j] << " ";
//			else 
//				cout << "INF ";
//		cout << endl;
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				g[i][k]=min(g[i][j]+g[j][k],g[i][k]);
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		cin >> x >> y;
		int ans=w[x]+w[y];
		int l=sto[x].idx,k=sto[y].idx;
		int res=0x3f3f3f3f;
		for(int i=0;i<l;i++)
			for(int j=0;j<k;j++){
				res=min(res,g[sto[x].car[i]][sto[y].car[j]]+sto[x].t[i]+sto[y].t[j]);
			}
		printf("%d\n",ans+res);
	} 
} 
