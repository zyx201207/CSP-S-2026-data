#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500010;
int a[maxn],s[maxn],n,m,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int t=a[1];
	for(int i=1;i<=n;i++) a[i]-=t;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n&&j<=n;i++){
		while(((j-i+1)*a[j]-(s[j]-s[i-1]))<=m&&i<=n&&j<=n) j++;
		ans=max(ans,j-i);
	}
	cout<<ans<<endl;
	return 0;
}

