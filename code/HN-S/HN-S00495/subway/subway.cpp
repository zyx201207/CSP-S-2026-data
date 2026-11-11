//40-60
#include<bits/stdc++.h>
using namespace std;
int w[500010],a[510][30],t[510][20010];
struct node{
	int x;
	long long int i;
};
vector<node> c[500010],g[510];	
vector<int> li[500010];
long long int dis[510];
int vis[510];
int C,N,M,D,Q;
bool operator <(node x,node y){
	return x.i>y.i;
}
long long int dijk(int x,int y){
	priority_queue <node> q;
	for(int i=1;i<=N;i++){
		dis[i]=1e18+7;
		vis[i]=0;
	}
	dis[x]=0,vis[x]=1;
	node st;
	st.x=x,st.i=0;
	q.push(st);
	while(!q.empty()){
		node h=q.top();
		q.pop();
		for(int i=0;i<g[h.x].size();i++){
			node y;
			y.x=g[h.x][i].x;
			//cout<<y.x<<endl;
			if(g[h.x][i].i+dis[h.x]<dis[y.x]){
				dis[y.x]=dis[h.x]+g[h.x][i].i;
				if(vis[y.x]==0){
					q.push(y);
					vis[y.x]=1;
				}
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cout<<sizeof(f)*8/1024/1024<<endl;

	cin>>C>>N>>M>>D>>Q;
	if(N<=500 && M<=20000){
		for(int i=1;i<=M;i++){
			cin>>w[i];
		}
		for(int i=1;i<=N;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				li[x].push_back(i);
				a[i][j]=x;
				t[i][x]=y;
				
			}
			for(int j=1;j<=k;j++){
				for(int l=1;l<=k;l++){
					if(j!=l){
						node tp;
						tp.x=a[i][j],tp.i=i;
						c[a[i][l]].push_back(tp);
					}
				}
			} 
		}
		for(int x=1;x<=M;x++){
			if(li[x].size()>1){
				for(int j=0;j<li[x].size();j++){
					for(int k=0;k<li[x].size();k++){
						if(j==k){
							continue;
						}
						node tp;
						tp.x=li[x][k],tp.i=t[li[x][j]][x]+t[li[x][k]][x];
						g[li[x][j]].push_back(tp);
						//cout<<li[x][j]<<" "<<li[x][k]<<" "<<tp.i<<endl;
						
					}
				}
			}
		}
		for(int u=1;u<=Q;u++){
			int x,y;
			cin>>x>>y;
			int fl=0;
			for(int i=0;i<c[x].size();i++){
				if(c[x][i].x==y){
					fl=c[x][i].i;
					break;
				}
			} 
			if(fl!=0){
				cout<<w[x]+w[y]+t[fl][x]+t[fl][y]<<endl;
				continue;
			}
			long long int ans=1e18;
			for(int i=0;i<li[x].size();i++){
				for(int j=0;j<li[y].size();j++){
					//cout<<li[x][i]<<" "<<li[y][j]<<endl;
					ans=min(ans,dijk(li[x][i],li[y][j])+t[li[x][i]][x]+t[li[y][j]][y]);
				}
			}
			cout<<w[x]+w[y]+ans<<endl;
			
		}
	}
	return 0;
}
/*
/*
 n___n
/'  ' \
\o ^ o/
/     \ 
--this is little white mouse,not hamster--
the last time,probably.
I have nothing to say,but wish you RP++.
*/

