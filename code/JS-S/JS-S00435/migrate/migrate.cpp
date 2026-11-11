#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,t;
ll n,d;
ll x[N];
ll ans,sum;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[n]-x[1]<=d){
			ans=0;
			cout<<ans<<'\n';
		}
		else
		{
			_ll cnt=x[2]-x[1];
			for(int i=1;i<=n;i++){
			//sum=0;
			//ans=0;
				for(int j=i;j<=n;j++){
					sum=x[j]-x[i];
					if(sum==2*d-cnt){
						//cout<<x[i]<<' '<<x[j]<<'\n';
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
