#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,a[500010],b[500005][505],vis[500010];
long long ans;
struct aa{
	int cnt,num;
};
vector<aa>e[500010];
void dfs(int t,int tt,int end,long long num){
	if(t==end){
		ans=min(ans,num+a[end]+b[end][tt]);
		return;
	}
	for(int i=0;i<e[t].size();i++){
		aa p=e[t][i];
		if(vis[p.num]==1)continue;
		if(p.cnt==tt){
			vis[p.num]=1;
			dfs(p.num,tt,end,num);
			vis[p.num]=1;
		}else{
			vis[p.num]=1;
			dfs(p.num,p.cnt,end,num+b[t][tt]+b[t][p.cnt]);
			vis[p.num]=0;
		}
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k,x,y,z;
		cin>>k;
		cin>>x>>z;
		b[x][i]=z;
		for(int j=2;j<=k;j++){
			cin>>y>>z;
			e[x].push_back({i,y});
			e[y].push_back({i,x});
			x=y;
			b[x][i]=z;
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		ans=2e11;
		vis[x]=1;
		for(int i=1;i<=n;i++){
			if(b[x][i]!=0){
				dfs(x,i,y,a[x]+b[x][i]);
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
