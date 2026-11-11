#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll c,t,n,d,m,x[2000005];
bool check(ll i, ll j){
	ll pos=x[i],cnt=0;
	for(int t=i+1;t<=j;t++){
		if(t==j){
			if((x[j]-pos)<=d){
				cnt++;
			}else{
				return false;
			}
		}else{
			if((x[t]-pos)<=d&&((x[t+1]-pos)>d)){
				pos=x[t];
				cnt++;
			}else if((x[t]-pos)>=d){
				return false;
			}
		}
	}
	return true;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

