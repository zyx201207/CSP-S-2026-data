#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,t,n,d,x[2000005],dis[2000005],cnt[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=1e18,cnt[j]=0;
			}dis[i]=0;cnt[i]=1;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int v=1;v<=n;v++){
					if(llabs(x[v]-x[u])<=d){
						if(dis[v]>dis[u]+1){
							dis[v]=dis[u]+1;
							cnt[v]=cnt[u];
							q.push(v);
						}else if(dis[v]==dis[u]+1){
							cnt[v]+=cnt[u];
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(cnt[j]==2)ans++;
			}
		}cout<<ans/2<<endl;
	}
	return 0;
}