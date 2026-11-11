#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,t;
vector<int>g[303];
int f[303],co,mask,dep,st;
void dfs(int u,int fa,int d){
	f[u]=co;
	if(dep<d){
		dep=d;
		st=u;
	}
	for(int v:g[u]){
		if(v==fa)continue;
		if(mask&(1<<(v-1)))dfs(v,u,d+1);
	}
} 
void solve(){
	int n,k,ans=INT_MAX,x,y;
	co=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		f[i]=0;
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);		
		g[y].push_back(x);		
	}
	for(mask=0;mask<(1<<n);mask++){
		int cnt=0,deeep=0;
		for(int i=0;i<n;i++){
			if(mask&(1<<i))cnt++;
		}
		if(cnt!=k)continue;
		for(int i=0;i<n;i++){
			if(mask&(1<<i)){
				dep=0;
				if(!f[i+1]){
					co++;
					dfs(i+1,0,0);
					dfs(st,0,0);
				}
				if(dep!=0)deeep=max(deeep,dep);
			}
		}
		if(co<=2&&deeep!=0)ans=min(ans,deeep);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 