#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,a[200007];
vector<ll> v[200007];
set<string>s;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]-a[i]<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(v[i].size()==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
