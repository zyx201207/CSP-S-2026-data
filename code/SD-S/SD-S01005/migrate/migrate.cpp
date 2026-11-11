#include<bits/stdc++.h>
using namespace std;
#define int long long
int ccc,t,n,k,a[2000009],f[2000009],d[2000009],vis[2000009],ans;
vector<int> v[2000009];
queue<int> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ccc>>t;
	while(t--){
		cin>>n>>k;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i],v[i].clear();
		for(int i=1,j=1;i<=n;i++){
			j=i+1;
			while(a[j]-a[i]<=k&&j<=n){
				v[i].push_back(j);
				j++;
			}
		}
		if(ccc==13||ccc==14){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			q.push(i);
			for(int j=1;j<=n;j++) f[j]=1e18,d[j]=0,vis[j]=0;
			f[i]=0;
			d[i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				//cout<<u<<'\n';
				for(int j=0;j<v[u].size();j++){
					if(f[v[u][j]]==f[u]+1){
						f[v[u][j]]=f[u]+1;
						d[v[u][j]]+=d[u];
					}else if(f[v[u][j]]>f[u]+1){
						f[v[u][j]]=f[u]+1;
						d[v[u][j]]=d[u];
						q.push(v[u][j]);
					}
				}
			}
			while(!q.empty()) q.pop();
			for(int j=1;j<=n;j++){
				if(d[j]==2) ans++;
			}
			//cout<<i<<": ";
			//for(int j=1;j<=n;j++) cout<<d[j]<<' ';cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
/*
³æÐè
ÔÆÁ¦
°×É×
³æÇÒ 
*/
