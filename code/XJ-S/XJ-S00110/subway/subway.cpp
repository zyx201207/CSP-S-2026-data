#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<deque>
#include<queue>
#include<set>
#include<string>
#include<stack>
#include<vector>
#include<map>
#include<list>
using namespace std;
int c,n,m,d,q,en,ans;
int a[505];
int w[505];
int f[505][505];
int vis[505];
void dfs(int id,int sum,int line){
	if(id==en){
		sum+=f[line][id];
		ans=min(ans,sum);
	}
	else{
		if(sum>ans) return;
		if(line!=0){
			for(int j=1;j<=m;j++){
				if(!vis[j]&&f[line][j]!=0){
					vis[j]=1;
					dfs(j,sum+f[line][j],line);
					vis[j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[id]&(1<<(i-1))){
					for(int j=1;j<=m;j++){
						if(!vis[j]&&f[i][j]!=0){
							vis[j]=1;
							dfs(j,sum+f[line][j]+f[i][j],i);
							vis[j]=0;
						}
					}
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[id]&(1<<(i-1))){
					for(int j=1;j<=m;j++){
						if(!vis[j]&&f[i][j]!=0){
							vis[j]=1;
							dfs(j,f[i][id],i);
							vis[j]=0;
						}
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int x,t;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			int t;
			cin>>t;
			a[t]|=(1<<(i-1));
			cin>>f[i][t];
		}
	}
	for(int i=1;i<=q;i++){
		int st;
		cin>>st>>en;
		ans=INT_MAX;
		dfs(st,0,0);
		cout<<w[st]+ans+w[en]<<'\n';
	}
	
	return 0;
}

