#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,a[2100000],vis[5100],dis[5100],cnt[5100];
vector<ll>ve[5100];
void SPFA(int x){
	queue<int>q;
	memset(dis,0x7f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	dis[x]=0;
	vis[x]=1;
	cnt[x]=1;
	q.push(x);
	while(!q.empty()){
		int t=q.front();q.pop();
		vis[t]=0;
		for(auto i:ve[t]){
			if(dis[i]>dis[t]+1){
				dis[i]=dis[t]+1;
				cnt[i]=cnt[t];
				if(vis[i])continue;
				vis[i]=1;
				q.push(i);
			}
			else if(dis[i]==dis[t]+1){
				cnt[i]+=cnt[t];
				if(vis[i])continue;
				vis[i]=1;
				q.push(i);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=10){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						ve[i].push_back(j);
//						ve[j].push_back(i);
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				SPFA(i);
				for(int j=1;j<=n;j++){
					ans+=(cnt[j]==2);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}