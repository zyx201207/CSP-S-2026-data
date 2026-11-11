#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn=2e5+10;

ll n,m;
ll a[maxn],ans=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--) ans&=a[i];
	cout<<ans;
	return 0;
}
