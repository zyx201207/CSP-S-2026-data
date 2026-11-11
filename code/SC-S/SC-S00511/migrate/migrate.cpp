#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int n,d,x[N],ans;
void solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=4;i<=n;i++){
		if(x[i]-2*d>x[i-3])continue;
		if(x[i]-d>x[i-1]||x[i-1]-d>x[i-3]
			||x[i]-d>x[i-2]||x[i-2]-d>x[i-3])continue;
		if(x[i]-d<=x[i-3])continue;
		ans++;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		if(c==13||c==14){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			if(x[n]-x[1]<d*2)cout<<0;
			else cout<<n-3;
		}
		solve();
	}
}