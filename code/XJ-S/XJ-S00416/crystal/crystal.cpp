#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],c[N],ans=1,maxn=-1e18;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) c[i]+=(a[i]-a[j]);
	for(int i=1;i<=n;i++) if(c[i]>=maxn&&c[i]<=m) maxn=c[i],ans=i;
	cout<<ans;
	return 0;
} 
