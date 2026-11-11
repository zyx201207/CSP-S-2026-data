#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int c,t,n,d,a[N],dis[N],f[N],res[400][400];
vector<int>e[N];
queue<int>q;
void dij(){
	while(!q.empty()){
		auto now=q.front();
		q.pop();
		int u=now;
		for(auto ow:e[u]){
			if(dis[ow]>dis[u]+1){
				dis[ow]=dis[u]+1;
				q.push(ow);
				f[ow]=max(f[u],1ll);
			}
			else if(dis[ow]==dis[u]+1){
				f[ow]+=f[u];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			e[i].clear();
			for(int j=1;j<=n;j++){
				res[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])>d){
					break;
				}
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=1e18;
				f[j]=0;
			}
			dis[i]=0;
			q.push(i);
			dij();
			for(int j=1;j<=n;j++){
				if(f[j]==2&&(res[i][j]==0&&res[j][i]==0)){
					ans++;
					res[i][j]++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
