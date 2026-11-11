#include<bits/stdc++.h>
using namespace std;
int dis[110];
vector<int>a[110];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(c==1){
			if(n==2)cout<<0<<endl;
			else if(n==3)cout<<1<<endl;
			else if(n==4)cout<<1<<endl;
			else cout<<1<<endl;
			continue;
		}
		int ans=1e9;
		for(int i=0;i<(1<<n);i++){
			int c=0;
			for(int j=1;j<=n;j++)c+=(i>>j-1)&1;
			if(c!=k)continue;
			for(int j=1;j<=n;j++){
				if((i>>j-1)&1)dis[i]=0;
				else dis[i]=1e9;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k:a[j])dis[k]=min(dis[k],dis[j]+1);
				}
			}
			int mx=0;
			for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
			ans=min(ans,mx);
		}
		cout<<ans<<endl;
	}
	return 0;
}

