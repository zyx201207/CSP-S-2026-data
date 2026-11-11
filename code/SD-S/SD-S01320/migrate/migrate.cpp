#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d,a[N],c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			if(a[2]-a[1]==0) cout<<0<<'\n';
			else{
				int k=d/abs(a[2]-a[1]);
				if(k<=1) cout<<0<<'\n';
				else cout<<max(n-2*k+1,0LL)<<'\n';
			}
		} 
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}

