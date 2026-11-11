#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n,ans=1;
const int N=2e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;m>=(abs(a[i+1]-a[i]))*i;i++){
		if((abs(a[i+1]-a[i]))*i<=m){
			m-=(abs(a[i+1]-a[i]))*i;
			ans++;
		}
	}
	cout<<ans;
}