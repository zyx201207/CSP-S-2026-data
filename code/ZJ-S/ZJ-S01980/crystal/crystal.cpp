#include<bits/stdc++.h>
#include<cassert>
using namespace std;
#define ll long long
const int N=5e5+10;
ll b[N],a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int j=1,ans=0;
	for(int i=1;i<=n;i++){
		while(1ll*(i-j+1)*a[i]-(b[i]-b[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<"\n";
	return 0;
}