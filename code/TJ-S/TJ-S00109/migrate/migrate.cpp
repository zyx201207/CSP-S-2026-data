#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 200005

int c,T,n,d,ans;
int a[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=2;i<=n;++i){
			if(a[i]-a[1]<=d) continue;
			int z=a[i]-a[1];
			int y=n-i+1;
			if(z==d*2-1){
				ans+=y;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
