#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int x[2000005];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int q=x[2]-x[1];
	int f=d/q;
	int ans=0;
	for(int i=2*f-1;i<=n;i+=f){
		ans+=n-i;
	}
	cout<<ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>c>>t;
	for(int _=0;_<t;_++){
		solve();
	}
} 
