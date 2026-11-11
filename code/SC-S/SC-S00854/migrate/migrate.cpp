#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int c,t;
void solve(){
	int n,d;
	ll a[N];
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n-3;i++){
		if((a[i+1]-a[i]<d)&&(a[i+2]-a[i+1]<d)&&(a[i+3]-a[i+2]<d)&&(a[i+2]-a[i]<=d)&&(a[i+3]-a[i+1]<=d)&&(a[i+3]-a[i]>d))
			ans++;
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}