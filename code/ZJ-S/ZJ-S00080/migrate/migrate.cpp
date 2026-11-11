#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define fs first
#define ss second

const ll N=2e6+7;

ll c,t;
ll n,d;
ll x[N];



ll minx[5007];
ll cnt[5007];

vector<int> T[5007];

void fun(ll pos){
	queue<pair<ll,ll> >q;
	memset(minx,0x3f,sizeof(minx));
	memset(cnt,0,sizeof(cnt));
	q.push({pos,0});
	minx[pos]=0;cnt[pos]=1;
	while(!q.empty()){
		auto now=q.front();q.pop();
		for(auto i:T[now.fs]){
			if(minx[i]>now.ss+1){
				minx[i]=now.ss+1;
				cnt[i]=1;
				q.push({i,now.ss+1});
			}
			else if(minx[i]==now.ss+1){
				++cnt[i];
				q.push({i,now.ss+1});
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n&&x[j]-x[i]<=d;j++){
				T[i].push_back(j);
			}
		}
//		for(int i=1;i<=n;i++){
//			for(auto e:T[i]){
//				cout<<e<<' ';
//			}
//			cout<<'\n';
//		}
//		cout<<"-----------------------------\n";
		for(int i=1;i<=n;i++){
			fun(i);
			for(ll j=i+1;j<=n;j++){
				ans+=(cnt[j]==2);
//				if(cnt[j]==2){
//					cout<<minx[j]<<' '<<cnt[j]<<' '<<i<<' '<<j<<'\n';
//				}
			}
//			cout<<"\n\n\n";
		}
		for(int i=1;i<=n;i++) T[i].clear();
		cout<<ans<<'\n';
	}
	
	return 0;
}