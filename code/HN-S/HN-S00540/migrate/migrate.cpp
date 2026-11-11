#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[200005],vis[200005],an[200005];
void spfa(int x){
	memset(vis,0x3f,sizeof(vis));
	queue<int> q;
	q.push(x);
	vis[x]=0;
	an[x]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=u+1;i<=n;i++){
			if(a[i]-a[u]>m){
				break;
			}
			if(vis[i]>vis[u]+1){
				vis[i]=vis[u]+1;
				q.push(i);
				an[i]=1;
			}else if(vis[i]==vis[u]+1){
				an[i]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=0,m=0;
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=1;j<n;j++){
			spfa(j);
			for(int i=1;i<=n;i++){
				if(an[i]>=2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
