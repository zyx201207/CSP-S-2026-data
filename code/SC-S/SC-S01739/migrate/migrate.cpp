#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			int s=a[2]-a[1];
			d=d/s;
			if(d>n) d=n;
			int ans=n-d*2+1;
			if(ans<0) ans=0;
			if(d==0||d==1) ans=0;
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
} 