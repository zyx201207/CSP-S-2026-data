#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,vis[15],cc[15],dep[1005],ans=1e18,p[1005][1005],mx[1005],cmx[1005];
vector<long long>s[1005];
void dfs2(long long x,long long cl){
	cc[x]=cl;
	for(int to:s[x]){
		if(vis[to]&&!cc[to]){
			dfs2(to,cl);
		}
	}
}
void dfs3(long long x,long long fa){
	dep[x]=dep[fa]+1;
	for(int to:s[x]){
		if(to!=fa){
			dfs3(to,x);
		}
	}
}
void dfs4(long long i,long long x,long long fa){
	p[i][x]=p[i][fa]+1;
	for(int to:s[x]){
		if(to!=fa){
			dfs4(i,to,x);
		}
	}
}
void dfs(long long x,long long sum){
	if(x>n){
		if(sum!=k){
			return ;
		}
		vector<long long>a;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				a.push_back(i);
			}
		}
		long long cl=0;
		memset(cc,0,sizeof(cc));
		for(int nw:a){
			if(!cc[nw]){
				dfs2(nw,++cl);
			}
		}
		if(cl<=2){
			long long mx=0;
			for(int i=1;i<=n;i++){
				long long mn=1e18;
				if(!vis[i]){
					dep[0]=-1;				
					dfs3(i,0);
					for(int j=1;j<=n;j++){
						if(vis[j]){
							mn=min(mn,dep[j]);
						}
					}
					mx=max(mx,mn);
				}
			}
			ans=min(ans,mx);
		}
		return ;
	}
	vis[x]=1;
	dfs(x+1,sum+1);
	vis[x]=0;
	dfs(x+1,sum);
}
long long ch(long long x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((mx[i]<=x||(mx[i]==x+1&&cmx[i]==1&&p[i][j]==mx[i]))&&(mx[j]<=x||(mx[j]==x+1&&cmx[j]==1&&p[j][i]==mx[j]))){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=1e18;
		for(int i=1;i<=n;i++){
			s[i].clear();
		}
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			s[x].push_back(y);
			s[y].push_back(x);
		}
		if(k<=2){
			for(int i=1;i<=n;i++){
				p[i][0]=-1;
				dfs4(i,i,0);	
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					long long mx=0;
					for(int k=1;k<=n;k++){
						if(i!=k&&j!=k){
							mx=max(mx,min(p[i][k],p[j][k]));
						}
					}
					ans=min(ans,mx);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}