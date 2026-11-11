#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],dp[2000005],dis[2000005],vis[2000005],f[2000005];
vector<int> g[2000005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==11||c==12){
			for(int i=1;i<=n;i++) cin>>a[i];
			if(n==1){
				cout<<"0\n";
				continue;
			}
			int p=a[2]-a[1];
			p=d/p;
			if(p==0||p==1){
				cout<<"0\n";
				continue;
			}
			int ans=max(0ll,n-(2*p-1));
			cout<<ans<<'\n';
			continue;
		}
		if(c==13||c==14){
			for(int i=1;i<=n;i++) cin>>a[i];
			if(n==1){
				cout<<"0\n";
				continue;
			}
			int flag=0;
			for(int i=1;i<=n;i++){
				if(a[i]-d<=a[1]&&a[i]+d>=a[n]) flag=i;
			}
			for(int i=1;i<=n;i++){
				if(i==flag) continue;
				f[i]=(a[i]+d>=a[n]?n:upper_bound(a+1,a+1+n,a[i]+d)-a-1);
				if(f[i]==flag) --f[i];
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				int nxt=f[f[i]];
				if(f[((f[i]-1==flag)?f[i]-2:f[i]-1)]<nxt&&f[f[i]]!=f[i]){
					++ans;
//					cout<<i<<' '<<f[i]<<' '<<f[f[i]]<<' '<<f[((f[i]-1==flag)?f[i]-2:f[i]-1)]<<'\n';
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
		if(n==1){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]+d>=a[j]){
					g[i].push_back(j);
					g[j].push_back(i);
				}
				else{
					break;
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[j]=1e9,vis[j]=0,dp[j]=0;
			dis[i]=0;
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
			q.push({0,i});
			dp[i]=1;
			while(!q.empty()){
				int x=q.top().second;q.pop();
				if(vis[x]) continue;
				vis[x]=1;
				for(int y:g[x]){
					if(dis[y]>dis[x]+1){
						dis[y]=dis[x]+1;
						dp[y]=dp[x];
						q.push({dis[y],y});
//						cout<<x<<' '<<y<<'\n';
					}
					else if(dis[y]==dis[x]+1) dp[y]+=dp[x];//cout<<x<<' '<<y<<'\n';;
				}
			}
			for(int j=i+1;j<=n;j++){
//				cout<<dis[j]<<' ';
				if(dp[j]==2) ++ans;
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
