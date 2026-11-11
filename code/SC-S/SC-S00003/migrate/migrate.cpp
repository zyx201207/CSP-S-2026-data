#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int c,t,n,m,a[maxn],ans;
map<int,bool>mp;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			mp[a[i]]=1;
		}
		for(int i=1;i<=n;++i){
			if(mp[a[i]+m+m-1]&&mp[a[i]+m]&&mp[a[i]+m-1]){
				ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
		mp.clear();
	}
	return 0;
}