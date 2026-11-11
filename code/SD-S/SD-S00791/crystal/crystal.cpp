#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define endl '\n'
using namespace std;

const int MAXN=5e5+10;

int n,ans=0;
ll m,a[MAXN];

int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll now=0;
	for(int r=1,l=1;r<=n;r++){
		now+=1ll*(r-l)*(a[r]-a[r-1]);
		while(now>m) now-=(a[r]-a[l++]);
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
