#include<bits/stdc++.h>
using namespace std;
int C,T,n,K,ans;
vector<int>E[1000010];
bool in[1000010],vis[1000010];
void dfs1(int x,int f){
	vis[x]=1;
	for(register int i=0,R=E[x].size();i<R;++i){
		if(E[x][i]==f||!in[E[x][i]])
			continue;
		dfs1(E[x][i],x);
	}
}
void dfs2(int x,int f,int cnt,int &d){
	if(in[x]){
		d=min(d,cnt);
		return;
	}
	for(register int i=0,R=E[x].size();i<R;++i){
		if(E[x][i]==f)
			continue;
		dfs2(E[x][i],x,cnt+1,d);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	if(C<=3){
		while(T--){
			cin>>n>>K;
			for(register int i=1;i<n;++i){
				register int u,v;
				cin>>u>>v;
				E[u].push_back(v);
				E[v].push_back(u);
			}
			ans=1e9;
			for(register int z=0,R=(1<<n);z<R;++z){
				if(__builtin_popcount(z)!=K)
					continue;
				for(register int i=0;i<n;++i)
					in[i+1]=((z>>i)&1),vis[i+1]=0;
				register int cnt=0;
				for(register int i=1;i<=n;++i)
					if(in[i]&&!vis[i])
						++cnt,dfs1(i,0);
				if(2<cnt)
					continue;
				cnt=0;
				for(register int i=1;i<=n;++i){
					register int dis=1e9;
					dfs2(i,0,0,dis);
					cnt=max(cnt,dis);
				}
				ans=min(ans,cnt);
			}
			cout<<ans<<'\n';
			for(register int i=1;i<=n;++i)
				E[i].clear();
		}
	}
	else if(C<=14){
		cin>>n>>K;
		int m=n/2;
		if(K==1)
			cout<<(m/2)+1<<'\n';
		else if(K<m)
			cout<<(m+1-K)/4+1<<'\n';
		else if(K<n)
			cout<<1<<'\n';
		else
			cout<<0<<'\n';
	}
	return 0;
}
