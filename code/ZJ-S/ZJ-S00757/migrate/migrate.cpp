#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,c,n,d,a[2000007],cnt[2000007],dis[2000007];
void init(){
	for(ll i=1;i<=n;i++){
		cnt[i]=0;
		dis[i]=INT_MAX;
	}
}
void solve(){
	if(c<=6){
		queue<ll>q;ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				dis[j]=INT_MAX;
			}
			q.push(i);
			dis[i]=0;
			while(q.size()){
				ll f=q.front();
				q.pop();
				for(ll i=f+1;i<=n;i++){
					if(a[i]-a[f]>d)break;
					if(dis[f]+1<dis[i]){
						dis[i]=dis[f]+1;
						cnt[i]=1;
						q.push(i);
					}else if(dis[f]+1==dis[i]){
						cnt[i]++;
						q.push(i);
					}
				}
				
			
			}	
			for(ll j=i+1;j<=n;j++){
					if(cnt[j]==2)ans++;
				}
				
		}
		cout<<ans<<'\n';
	}
	if(c<=12&&c>=11){
		ll idx=upper_bound(a+1,a+1+n,a[1]+d)-a-1;
		if(idx<=2){
			cout<<0<<'\n';
			return;
		}
		idx--;
		cout<<max(0ll,n-2*idx+1)<<'\n';
		return;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		init();
		solve();
	}
	return 0;
}

