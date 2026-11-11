#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int g[N][N],dist[N];
int a[1009],b[1009],c[1009],inq[1009];
int n,m,d,q;
void spfa(int s){
	for(int i=0;i<1005;i++){
		inq[i]=0;
		dist[i]=0x3f3f3f;
	}
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u;
		u=q.front();
		q.pop();
		inq[u]=false;
		for(int i=0;i<n;i++){
			if(g[u][i]!=0x3f3f3f&&inq[i]==false&&dist[u]!=0x3f3f3f){
				if(dist[u]+g[u][i]<dist[i]){
					q.push(i);
					inq[i]=true;
					dist[i]=dist[u]+g[u][i];
				}		
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<1005;i++){
		for(int j=0;j<1005;j++){
			g[i][j]=0x3f3f3f;
		}
	} 
	int T;
	cin>>T;
	cin>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		cin>>b[0]>>c[0];
		for(int i=1;i<k;i++){
			cin>>b[i]>>c[i];
			g[b[i]][b[i-1]]=c[i]+c[i-1];
			g[b[i-1]][b[i]]=c[i]+c[i-1];
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		spfa(x);
		cout<<dist[y]+a[x]+a[y]<<endl;
	}
	return 0;
} 
