#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll c,t;
ll pos[N],dis[N],cnt[N];
ll ans;
bool vis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	if(t>10000){
		while(t--){
			ll n,d;
			cin>>n>>d;
			cout<<0<<"\n";
		}
	}
	while(t--){
		ans=0;
		memset(pos,0,sizeof pos);
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		ll n,d;
		ll minn=1e18+10;
		cin>>n>>d;
		if(n<=300){
			for(int i=1;i<=n;i++){
				cin>>pos[i];
				minn=min(minn,pos[i]);
			}
			if(minn<0){
				for(int i=1;i<=n;i++) pos[i]+=(0-minn+1);
			}
			int idx;
			for(int i=1;i<=n;i++) vis[pos[i]]=1;
			for(int i=1;pos[i]<=pos[1]+d;i++){
				if(vis[i]) dis[i]=0,idx=i;
			}
			for(int i=idx+1;i<=n;i++){
				for(int j=max(0ll,i-d);j<i;j++){
					if(vis[j]) dis[i]=min(dis[i],dis[j]+1);
				}
				for(int j=max(0ll,i-d);j<i;j++){
					if(vis[j]&&(dis[j]==dis[i]||dis[j]==dis[i]-1)) cnt[i]++; 
				}
			}
			for(int i=1;i<=n;i++) if(cnt[pos[i]]==2) ans++;
			cout<<ans<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
	return 0;
}