#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e6	+34,INF=0X3f3f3f3f;
ll c,t,ans=0;
ll a[N];
void solve(){
	ll n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=4;i<=n;i++){
		bool f1=(a[i-2]-a[i-1]<=d)&&(a[i]-a[i-2]<=d);
		bool f2=(a[i]-a[i-1]<=d)&&(a[i-1]-a[i-3]<=d);
		if(f1&&f2)ans++;
	}
	cout<<ans<<endl;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
