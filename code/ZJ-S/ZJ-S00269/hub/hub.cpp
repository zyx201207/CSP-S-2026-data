#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,INF=1e15;
int C,t,n,k,u[N],v[N],f[N],ans;
int find(int x){
	return (x==f[x]?x:f[x]=find(f[x]));
}
void un(int u,int v){
	int U=find(u),V=find(v);
	if(U!=V){
		f[U]=V;
	}
}
bool check(int k){
	vector<int>G[N];
	for(int i=1;i<n;i++){
		if(k&1){
			G[u[i]].push_back(v[i]);
			G[v[i]].push_back(u[i]);
			un(u[i],v[i]);
		}
	}
	int id[2],kk=0,cnt[2];
	for(int i=1;i<=n;i++){
		if(f[i]==i){
			id[kk++]=i;
			if(kk>2){
				return false;
			}
		}
		cnt[id[i]]++;
	}
	ans=min(ans,min(n-cnt[1],n-cnt[2]));
}
void dfs(){
	int q=(1<<(q-1))-1;
	for(int mask=1;mask<=q;mask++){
		if(check(mask)){
			ans++;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>t;
	while(t--){
		cin>>n>>k;
		vector<int>G[N];
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		ans=INF;
		dfs();
		cout<<ans<<'\n';
	}
	return 0;
}
