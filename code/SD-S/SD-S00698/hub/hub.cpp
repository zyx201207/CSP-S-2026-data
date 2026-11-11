#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int maxn=1e6+7;
int c,t,n,k,s[maxn],vis[maxn],vis1[maxn],vis2[maxn],ti,dep[maxn],tim,ans=100000;
vector<int>g[maxn],g1[maxn];
void dfs1(int x){
	vis1[x]=ti;
	for(auto v:g[x]){
		if(vis[v]==1&&vis1[v]==0){
			dfs1(v);
		}
	}
}
void dfs2(int x){;
	vis2[x]=1;
	for(auto v:g1[x]){
		if(vis2[v]==0){
			dep[v]=min(dep[v],dep[x]+1);
			dfs2(v);
		}
	}
	
}
void dfs(int x){
	if(x==k){
		f(i,1,n){
			vis[i]=0;
			vis1[i]=0;
			vis2[i]=0;
			dep[i]=10000;
			ti=0;
			g1[i].clear();
		}
		f(i,1,k){
			vis[s[i]]++;
		}
		f(i,1,n){
			if(vis[i]>1){
				return ;
			}
		}
	//	cout<<1;
		f(i,1,k){
			if(!vis1[s[i]]){
				ti++;
				dfs1(s[i]);
			}
		//	cout<<s[i]<<" ";
		}
	//	cout<<ti<<endl;
		if(ti>2){
			return;
		}
		f(i,1,n){
			g1[i]=g[i];
		}
		f(i,1,k){
			f(j,1,k){
				if(i!=j){
					g1[s[i]].push_back(s[j]);
					g1[s[j]].push_back(s[j]);
				} 
			}
		}
	//	cout<<endl;
		f(i,1,k){
			f(j,1,n){
				vis2[j]=0;
			}
			dep[s[i]]=0;
			dfs2(s[i]);
		}
//		f(i,1,n){
//			cout<<dep[i]<<" ";
//		}
//		cout<<endl;
		int cnt=0;
		f(i,1,n){
			cnt=max(cnt,dep[i]);
		}
		ans=min(ans,cnt);
		return;
	}
	++x;
	for(int i=1;i<=n;i++){
		s[x]=i;
		dfs(x);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1000000;
		f(i,1,n){
			g[i].clear();
		}
		f(i,1,n-1){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0);
		cout<<ans<<"\n";
	}
	return 0;
}



