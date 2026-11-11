#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=5e5+5;
ll n,m;
ll a[N],g[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) g[i]=g[i-1]+a[i];
	ll ans=0,j=n;
	for(int i=n;i>=1;i--){
		while(j>0&&(a[i]*(i-j+1)-(g[i]-g[j-1]))<=m) j--;
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
} 
