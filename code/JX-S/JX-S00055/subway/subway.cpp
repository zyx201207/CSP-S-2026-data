#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int m,w[500005],n,a[505][500005],t[505][500005],d,k[500005];
int e[500005],ne[500005],idx,h[500005],bs[500005];
int dist[500005];
void add(int a,int b,int c){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++,bs[idx]=c;
}
int bfs(int x,int y){
	memset(dist,0x3f,sizeof dist);
	priority_queue<PII> q;
	q.push({x,0});
	while(q.size()){
		PII hh=q.top();
		q.pop();
		for(int i=h[hh.first];i!=-1;i=ne[i]){
			int j=e[i];
			//cout<<hh.first<<" "<<j<<endl;
			if(dist[j]>=bs[j]+hh.second){
				//cout<<j<<" "<<bs[j]<<endl;
				dist[j]=bs[j]+hh.second;
				q.push({j,dist[j]});
			}
		}
		
		
	}
	return dist[y];
}
int main(){
	
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(h,-1,sizeof h);
    int c,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int u=1;u<=k[i];u++){
				add(a[i][j],a[i][u],t[i][j]+t[i][u]);
			}
		}
	}
	
	cout<<t[2][1]<<" "<<t[2][2]<<endl;
	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)+w[x]+w[y]<<endl;
	}
    return 0;
}
