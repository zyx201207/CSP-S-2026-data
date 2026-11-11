#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,a[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		ll n,p=1;
		unsigned ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]<=d) continue;
			if(a[i+1]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+2]<=d) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
