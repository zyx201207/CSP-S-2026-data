#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,minn,f[10001],ff[10001];
void bfs(int m,int s,int z,vector<int>mpp[4001]){
	for(int i:mpp[m]){
		if(i==s){
			continue;
		}
		f[i]=min(f[i],z);
		bfs(i,m,z+1,mpp);
	}
}
void dfs(int x,int s,vector<int>v[4001]){
	int ff[10001];
	if(x==k+1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,f[i]);
		}
		minn=min(maxx,minn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==s){
			continue;
		}
		for(int j=1;j<=n;j++){
			ff[j]=f[j];
		}
		f[i]=0;
		bfs(i,0,1,v);
		dfs(x+1,i,v);
		for(int j=1;j<=n;j++){
			f[j]=ff[j];
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		vector<int>mp[4001];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		if(n==k){
			cout<<0;
		}
		else{
			if(n<=9||k<=2){
				memset(f,0x3f3f3f3f,sizeof(f));
				minn=0x3f3f3f3f;
				dfs(1,0,mp);
				cout<<minn;
			}
			else{
				cout<<n/k;
			}
		}
		cout<<'\n';
	}
	return 0;
}
