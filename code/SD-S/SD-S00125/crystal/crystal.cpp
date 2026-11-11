#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,s,a[N],f[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) f[i]=f[i-1]+a[i]-a[i-1];
	int l=1,r=1;
	while(r<=n){
		while(r<=n&&s<=m) s+=(r-l+1)*(f[r+1]-f[r]),r++;
		ans=max(ans,r-l);
		while(l<n&&s>m) s-=a[r]-a[l],l++; 
	}
	cout<<ans;
	return 0; 
}
