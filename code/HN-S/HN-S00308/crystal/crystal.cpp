#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1;
	for(int r=1;r<=n;r++){
		while((r-l+1)*a[r]-(s[r]-s[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}

