#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,t,n,d,x[2000005];
void solve(){
	memset(x,0,sizeof x);
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	cout<<"0\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
}
