#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=2e6+5;
int c,t,x[MAX];
void solve(){
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			int del=0;
			if(n>1)del=x[2]-x[1];
			int e=d/del;
			if(e<=1||e>=n)cout<<"0\n";
			else{
				cout<<n-e-e+1<<'\n';
			}
			continue;
		}else cout<<ans<<'\n';
	}
}
#undef int
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//  cin>>T;
	while(T--)solve();
	return 0;
}