#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int c,T;
int n,m,ans=0;
bool vis[100050];
bool vec[15][15];
queue<pair<int,int>> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		memset(vec,0,sizeof(vec));
		for(int i=1; i<=n-1; i++){
			int u,v;
			cin>>u>>v;
			vec[u][v]=vec[v][u]=true;
		}
		for(int k=1; k<=(1<<m)-1; k++){
			bool v[100050];
			memset(v,0,sizeof(v));
			int num=k;
			for(int i=0; i<=m-1; i++){
				if((num>>i)&1){
					v[i+1]=true;
				}
			}
			for(int i=1; i<=n; i++){
				if(v[i]==false){
					int dis=0;
					memset(vis,0,sizeof(vis));
					while(q.empty()==false) q.pop();
					q.push({i,0});
					while(q.empty()==false){
						int u=q.front().first,x=q.front().second;
						q.pop();
						if(v[u]==true){
							dis=x;
							break;
						}
						for(int v=1; v<=n; v++){
							if(vec[u][v]==true&&vis[v]==false){
								vis[v]=true;
								q.push({v,x+1});
							}
						}
					}
					ans=max(ans,dis);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
