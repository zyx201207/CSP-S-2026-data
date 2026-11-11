#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,minn=1e9,mini;
int a[N],v[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2&&i<n) ans+=n/i;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}

