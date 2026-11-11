#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define inf 0x3f3f3f3f
ll c,T;
vector<ll> v;
ll n,d,x,ans;
ll a[5010][5010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			v.push_back(x);
		}
		ll bu=1;
		for(int i=0;i<n;i++){
			ll g=v[i];
			for(int j=i;j<n;j++){
				if(v[j]-g<=d){
					a[i][j]=bu;
				}else{
					bu++;
					g=v[j];
					a[i][j]=bu;
				}
			}
		}
		for(int i=0;i<n;i++){
			ll l=i;
			for(int j=i;j<n;j++){
				if(a[i][j]!=a[i][j+1]){
					if(j-l-1==2){
						ans++;
					}
					l=j-1;
				}
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}
