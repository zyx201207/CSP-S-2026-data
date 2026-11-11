#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans12,c12,c,n,m,d,q,w[500005],k,a,t,flagc[1005],flags[1005],l,r,ans,f[1005][1005];
struct node{
	int v,w;
};
vector<node>sub[1005],city[1005],city12[500005];
int dfs(int l,int r){
	if(l==r)return 0;
	flagc[l]=1;
	if(f[l][r]!=-1)return f[l][r];
	int p=1e18;
	for(auto c:city[l]){
		if(flags[c.v]==0){
			flags[c.v]=1;
			for(auto s:sub[c.v])
				if(flagc[s.v]==0){
					p=min(p,c.w+s.w+dfs(s.v,r));
					flagc[s.v]=0;
				}
			flags[c.v]=0;
		}
	}
	if(p==1e18)return 4e18;
	return f[l][r]=p;
}
void bfs(int l,int r){
	queue<node>q;
	flagc[l]=1;
	q.push({l,0});
	while(q.size()){
		node t=q.front();q.pop();
		for(auto c:city12[t.v])
			for(auto s:sub[c.v])
				if(flagc[s.v]==0){
					flagc[s.v]=1;
					q.push({s.v,t.w+2});
					if(s.v==r){
						ans12=(t.w+2)*c12;
						return;
					}
				}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			c12=t;
			sub[i].push_back({a,t});
			if(c>=12)city12[a].push_back({i,t});
			else city[a].push_back({i,t});
		}
	}
	if(c>=12){
		while(q--){
			cin>>l>>r;bfs(l,r);
			ans=ans12+w[l]+w[r];
			cout<<ans<<'\n';
		}
		return 0;
	}
	memset(f,-1,sizeof(f));
	while(q--){
		cin>>l>>r;
		memset(flagc,0,sizeof(flagc));
		memset(flags,0,sizeof(flags));
		ans=dfs(l,r)+w[l]+w[r];
		cout<<ans<<'\n';
	}
	return 0;
}
