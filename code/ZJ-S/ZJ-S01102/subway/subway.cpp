#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M=5e5+5;
int w[M];
int sx,ex;
const int N=1005;
int a[N][205];
vector<int>v[N][205];
long long ans=1e18;
bool vis[N][205];
void dfs(int id,int x,long long s){
	if(s>=ans)return;
	if(x==ex){
		ans=min(ans,s+a[ex][id]);
		return;
	}
	//»»³Ë
	for(int i=1;i<=n;i++){
		if(a[x][i]!=0&&!vis[x][i]){
			vis[x][i]=1;
			if(x!=sx)dfs(i,x,s+a[x][id]+a[x][i]);
			else dfs(i,x,s+a[x][i]);
			vis[x][i]=0;
		}
	}
	for(int i=0;i<v[x][id].size();i++){
		int nx=v[x][id][i];
		if(vis[nx][id])continue;
		vis[nx][id]=1;
		dfs(id,nx,s);
		vis[nx][id]=0;
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(k==1){
				int aa,t;
				cin>>aa>>t;
				a[aa][i]=t;
			}else if(k==2){
				int aa,b,c,d;
				cin>>aa>>b>>c>>d;
				a[aa][i]=b;
				a[c][i]=d;
				v[aa][i].push_back(c);
				v[c][i].push_back(aa);
			}
		}
		while(q--){
			cin>>sx>>ex;
			ans=1e18;
			for(int i=1;i<=n;i++){
				if(a[sx][i]!=0){
					dfs(i,sx,0);
					break;
				}
			}
			ans+=w[sx]+w[ex];
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}
