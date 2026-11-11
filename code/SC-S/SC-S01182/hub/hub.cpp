#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=205+5;
ll c,T,n,k,d,q,w[N],num,mn=1e9,cnt[N],vis[N],l;
vector<int>g[N];
void dfs2(int fa,int st,ll num){
	cnt[st]=min(num,cnt[st]);
	for(auto u:g[st]){
		if(u==fa)continue;
		dfs2(st,u,num+1);
	}
}
void dfs3(int fa,int st){
	if(vis[fa]==0&&vis[st]==1)l++;
//	cout<<fa<<" "<<vis[fa]<<" "<<st<<" "<<vis[st]<<" "<<l<<"\n";
	for(auto u:g[st]){
		if(u==fa)continue;
		dfs3(st,u);
	}
}
void dfs1(int cur,string s,int cnt1){
//	cout<<s<<"\n";
	if(cur>n){
		if(cnt1==k){
			l=0;
			for(int i=1;i<=n;i++)cnt[i]=1e9,vis[i]=0;
			for(int i=0;i<s.size();i++){
				
				if(s[i]=='1'){
					dfs2(0,i+1,0);
					vis[i+1]=1;
				}
			}
			dfs3(0,1);
			ll sum=0;
			if(l<=2){
				for(int i=1;i<=n;i++)sum=max(sum,cnt[i]);
				mn=min(mn,sum);
			}
//			for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";
//			cout<<s<<" "<<l<<" "<<sum<<"\n";
		}
		return ;
	}
	dfs1(cur+1,s+"1",cnt1+1);
	dfs1(cur+1,s+"0",cnt1);
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		mn=1e9;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1,"",0);
		cout<<mn<<"\n";
	}
	return 0;
}