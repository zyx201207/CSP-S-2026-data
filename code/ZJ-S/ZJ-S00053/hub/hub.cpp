#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dep[1000005],f[1000005];
vector<int>g[1000005];
bitset<1000005>vis;
void dfs(int u,int fa){
	f[u]=fa;
	if(vis[u])dep[u]=0;
	else if(u^1)dep[u]=dep[fa]+1;
	else dep[u]=1e9;
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
		dep[u]=min(dep[u],dep[v]+1);
	}
}
bool check(int x){
	for(int i=3;i<(1<<n);i++){
		if(__builtin_popcount(i)^k)continue;
		vis&=0;
		int I=i;
		for(int j=I&(-I);I;I-=j,j=I&(-I))vis[(31^__builtin_clz(j))+1]=1;
		dfs(1,0);
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j])continue;
			bool flag=0;
			for(int k=1;k<=n;k++){
				if(!vis[k])continue;
				if(f[j]==k){
					flag=1;
					break;
				}
			}
			if(!flag)cnt++;
		}
		if(cnt>2)continue;
		bool flag=0;
		for(int j=1;j<=n;j++){
			if(dep[j]>x){
				flag=1;
				break;
			}
		}
		if(!flag)return 1;
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int u,v,i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==13||c==14){
			int m=(n+1)>>1;
			if(k==n)cout<<"0\n";
			else if(k>=m)cout<<"1\n";
			else{
				for(int i=2;i<=n;i++){
					int l=i,r=m-2*i,cnt=1;
					if(l<=r)cnt=r-l+2;
					if(k>=cnt){
						cout<<i<<'\n';
						break;
					}
				}
			}
			continue;
		}
		int l=0,r=n-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
