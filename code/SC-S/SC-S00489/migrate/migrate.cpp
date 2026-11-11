#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N=2e6+8;
int c,t,n,d,x[N],dp[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n==1||x[3]-x[1]>d){
			cout<<0<<'\n';
		}else{
			cout<<n-3<<'\n';
		}
	}
	return 0;
}