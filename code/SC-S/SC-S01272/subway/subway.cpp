#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qi;
int w1[500001];
int a[600][600],t[600][600],k[600];
int sx,sy,ex,ey;
int b[510000]={0};
struct E{
	int u,to,w;
}e[1000000];
bool cmp(E a,E b){
	return a.u<b.u;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qi;
	for(int i=1;i<=m;i++){
		cin>>w1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	int bian=0;
	for(int i=1;i<=n;i++){
		b[a[i][1]]++;
		for(int j=2;j<=k[i];j++){
			b[a[i][j]]++;
			e[++bian].u=a[i][j-1];
			e[bian].to=a[i][j];
			e[bian].w=0;
			e[++bian].to=a[i][j-1];
			e[bian].u=a[i][j];
			e[bian].w=0;
		}
	}
	int zhao=m+1;
	for(int i=1;i<=m;i++){
		if(b[i]>1){
			for(int i1=1;i1<=n;i1++){
				for(int j=1;j<=k[i];j++){
			        if(a[i1][j]==i){
			        	e[++bian].u=a[i1][j];
						e[bian].to=zhao;
						e[bian].w=t[i1][j];
						e[++bian].to=a[i1][j];
						e[bian].u=zhao;
						e[bian].w=t[i1][j];
					}
				}
			}
			zhao++;
		}
	}
	sort(e+1,e+1+bian,cmp);
	for(int i=1;i<=bian;i++){
		cout<<e[i].u<<" "<<e[i].to<<" "<<e[i].w;
	}
	for(int i=1;i<=qi;i++){
		int dis[m+1]={0};
		for(int j=1;j<=m;j++) dis[j]=2147483647;
		int x,y;
		queue<pair<int,int>> q;
		cin>>x>>y;
		dis[x]=0;
		q.push({x,0});
		int vis[m+11]={0};
		while(!q.empty()){
			auto w=q.front();
			q.pop();
			int x1=w.first;
			int w1=w.second;
			for(int p=1;p<=bian;p++){
				if(e[p].u==x1){
					if(dis[e[p].to]>dis[e[p].u]+e[p].w){
						dis[e[p].to]=dis[e[p].u]+e[p].w;
						q.push({e[p].to,dis[e[p].to]}); 
					}
				}
			}
		}
		cout<<dis[y]<<endl;
	}
	return 0;
}