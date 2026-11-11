#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qs,x,y;
long long ans=1e18;
long long w[500010];
int e[510][50010];
vector<int>q[510];
void dfs(int u,long long sum,int l,int f){
	if(sum>ans)return;
	if(u==y){
		long long ds=sum+w[u];
		ans=min(ans,ds);
		return;
	}
	for(int i=1;i<=n;i++){
		bool f=false;
		int h;
		if(e[i][u]==0)continue;
		h=e[i][u];
		for(auto v:q[i]){
			if(f){
				if(v==y)sum+=e[i][v];
				dfs(v,sum+h,i,f);
				if(v==y)sum-=e[i][v];
			}
			if(v==u){
				if(i!=l&&i!=f){
					if(v==y)sum+=e[i][v];
					dfs(v,sum+h,i,l);
					if(v==y)sum-=e[i][v];
					break;
				}
				f=true;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		for(int j=1;j<=s;j++){
			int u,tick;
			cin>>u>>tick;
			e[i][u]=tick;
			q[i].push_back(u);
		}
	}
	for(int i=1;i<=qs;i++){
		ans=1e18;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			if(e[j][x]>0)dfs(x,w[i],j,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}