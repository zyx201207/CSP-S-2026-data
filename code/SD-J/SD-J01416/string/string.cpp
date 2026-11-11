#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
const int N=2e5+145;
int a[N];
char c[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	ll ans=0;
	while (l<r){
		int jan=min(a[l],a[r]);
		a[l]-=jan;
		a[r]-=jan;
		if (c[l]!=c[r]) ans+=1ll*jan;
		if (a[l]==0) l++;
		if (a[r]==0) r--;
	}
	cout<<ans<<"\n";
	return 0;
}

