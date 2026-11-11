#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int w2[500020];
int a[501][20020];
int t[501][20020];
int dis[500050];
int c,n,m,d,q;
vector<PII> g[500050];
bool st[200020];
int main(){
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w2[i];
	}
	//for(int i=1;i<=m;i++){
	//	cout<<w2[i]<<" ";
	//}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i][j]=x;t[i][x]=y;
			//cout<<a[i][j]<<" "<<t[i][x]<<" "<<2<<endl;
		}
		for(int j=1;j<=k;j++){
			for(int _=j+1;_<=k;_++){
				g[j].push_back({i,_});
			}
		}
	}
	while(q--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=t[i][j]=0;
			}
			dis[i]=0x3f3f3f3f;
		}
		int x,y;
		cin>>x>>y;
		dis[x]=0;
		queue<int> q;
		q.push(x);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			//cout<<1<<endl;
			st[u]=0;
			for(int mm=0;mm<g[u].size();mm++){
				PII ite=g[u][mm];
				int i = ite.first;
				int j = ite.second;
				int v=a[i][j];
				int w=a[i][v];
				int ww=a[i][u];
				if(dis[u]+a[i][u]+a[i][v]<dis[v]){
					dis[v]=dis[u]+a[i][u]+a[i][v];
					if(!st[v]){
						st[v]=1;
						q.push(v);
					}
					
				}
			}
		}
		cout<<dis[y]+w2[x]+w2[y]<<endl;;
	}
}

