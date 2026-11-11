#include<bits/stdc++.h>
using namespace std;
vector<int>vec[1000005];int n,k,t;
namespace subtask1{
	int ans,fa[25],dep[25];
	void dfs1(int u,int fa){
		subtask1::fa[u]=fa;dep[u]=dep[fa]+1;
		for(int v:vec[u])if(v!=fa)dfs1(v,u);
	}
	int dis(int x,int y){
		if(dep[x]<dep[y])swap(x,y);
		int ans=0;
		for(;dep[x]>dep[y];)x=fa[x],ans++;
		for(;x!=y;)x=fa[x],y=fa[y],ans+=2;
		return ans;
	}
	void dfs2(int x,vector<int>vec){
		if(x==n+1){
			if(vec.size()!=k)return;
//			for(int i:vec)cout<<i<<' ';cout<<'\n';
			int res=0;
			for(int i:vec)for(int j:vec)res+=(dis(i,j)==1);
			res/=2;
			if(res!=k-1&&res!=k-2)return;
			res=0;
			for(int i=1;i<=n;i++){
				int tmp=1e9;
				for(int j:vec)tmp=min(tmp,dis(i,j));
				res=max(res,tmp);
			}
//			cout<<res<<'\n';
			ans=min(ans,res);
			return;
		}
		if(vec.size()>k||vec.size()+(n-x+1)<k)return;
		dfs2(x+1,vec);
		vec.push_back(x);
		dfs2(x+1,vec);
		vec.pop_back();
	}
	void main(){
		while(t--){
			ans=1e9;
			cin>>n>>k;
			for(int i=1;i<=n;i++)vec[i].clear();
			for(int i=1;i<n;i++){
				int u,v;cin>>u>>v;
				vec[u].push_back(v);
				vec[v].push_back(u);
			}
			dfs1(1,0);
			dfs2(1,{});
			cout<<ans<<'\n';
		}
	}
};
namespace subtask2{
	void main(){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;cin>>u>>v;
			}
			cout<<((n-1)/2+2-k+3)/4<<'\n';
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c;cin>>c>>t;
	if(c<=3)subtask1::main();
	if(c==13||c==14)subtask2::main();
	return 0;
}

