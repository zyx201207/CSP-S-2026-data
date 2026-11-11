#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,mp[10010][10010],u,v,mx,mxi;
int m[10010];
void dfs(int a,int k){
	if(k>mx){
		mx=k,mxi=a;
	}
	for(int i=1;i<=n;i++){
		if(mp[a][i]){
			m[a]=1;
			dfs(i,k+1);
			m[a]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			mp[u][v]=1;
		}
		dfs(1,0);
		memset(m,0,sizeof(m));
		dfs(mxi,0);
		cout<<(mx-1)%3+1;
		mxi=0;
		memset(m,0,sizeof(m));
	}
}
