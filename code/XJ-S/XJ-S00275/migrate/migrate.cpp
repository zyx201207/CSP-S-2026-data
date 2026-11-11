#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,t,x,n,d[N];
signed main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>x;
		for(int i=1;i<=n;i++)
			cin>>d[i];
		int h=1,t=4;
		while(t<=n){
			if(d[t]-d[h+1]<=x&&d[t]-d[h+1]<=x) ans++;
			h++,t++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
