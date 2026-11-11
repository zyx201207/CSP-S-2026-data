#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
const int N=5e5+25;

ll n,m;
ll a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	i128 usd=0;
	int ans=1;
	for (int l=1,r=2;r<=n;++r){
		usd+=(i128)(a[r]-a[r-1])*(r-l);
		while (usd>m){
			usd-=(a[r]-a[l]);
			++l;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}//crystal
