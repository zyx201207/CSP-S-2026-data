#include<bits/stdc++.h>
using namespace std;
const int N=2000010;

int c,t,n,k;
vector<int> s[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
		if(k==n){
			cout<<0<<'\n';
			break;
		}
		if(k>=n/2){
			cout<<1<<'\n';
			break;
		}
		if(k==2){
			int ans=0x3f3f3f3f;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int res=0;
					queue<int> q;
					int dis[1010];
					dis[i]=dis[j]=0;
					q.push(i);
					q.push(j);
					while(!q.empty()){
						int u=q.front();
						q.pop();
						for(auto v:s[u]){
							if(dis[v]>dis[u]+1){
								dis[v]=dis[u]+1;
								res=max(dis[v],res);
								q.push(v);
							}
						}
					}
					ans=min(ans,res);
				}
			}
			cout<<ans;
			break;
		}
		int k1=k/2-1;
		cout<<(n/2-k1*2)/4+1<<'\n';
	}
	return 0;
}
