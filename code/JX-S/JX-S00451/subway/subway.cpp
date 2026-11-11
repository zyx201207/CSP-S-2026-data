#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,w[1000000],n,m,d,q,vis[1000000],xx,yy,ans;
vector<int> a[505],jl[100000];
struct node{
	int v,t;
};
vector<node> t[1000];
void dfs(int x,int sum,int j,int step,int z){
	if(x==yy||step>10000*m){
		if(x==yy){
			if(z==0){
				for(unsigned i=0;i<t[x].size();i++){
					if(t[x][i].v==j){
						ans=min(ans,sum+t[x][i].t);
						break;
					}
				}
			}
			else ans=min(ans,sum);
		}
		return;
	}
	if(z==1){
		for(unsigned i=0;i<a[j].size();i++){
			if(vis[a[j][i]]==0){
				vis[a[j][i]]=1;
				int num=0;
				for(unsigned k=0;k<t[a[j][i]].size();k++){
					if(t[a[j][i]][k].v==j) num=t[a[j][i]][k].t;
				}
				dfs(a[j][i],sum+num,j,step+1,0);
				vis[a[j][i]]=0;
			}
		}
	}
	else{
		for(unsigned i=0;i<a[j].size();i++){
			if(vis[a[j][i]]==0){
				vis[a[j][i]]=1;
				dfs(a[j][i],sum,j,step+1,0);
				vis[a[j][i]]=0;
			}
		}
		for(unsigned i=0;i<jl[x].size();i++){
			int num=0;
			for(unsigned k=0;k<t[a[j][i]].size();k++){
				if(t[a[j][i]][k].v==j) num=t[a[j][i]][k].t;
			}
			dfs(x,sum+num,jl[x][i],step+1,1);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			jl[x].push_back(i);
			t[x].push_back({i,y});
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		ans=0x3f3f3f3f;
		cin>>xx>>yy;
		for(unsigned i=0;i<jl[xx].size();i++) dfs(xx,0,jl[xx][i],0,1);
		cout<<ans+w[xx]+w[yy]<<endl;
	}
	return 0;
}
