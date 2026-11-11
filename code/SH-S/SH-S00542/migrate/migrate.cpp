#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		map<ll,ll> mp,vis,p;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			mp[x[i]]++;
			p[x[i]]=i;
		}
		int ans=0;
		d=2*d-1;
		for(int i=1;i<=n;i++){
			if(!vis[x[i]]&&p[x[i]+d]-p[x[i]]>2){
				vis[x[i]]=1;
				ans+=mp[x[i]+d];
			}
		}
		cout<<ans<<"\n";
	}
} 
