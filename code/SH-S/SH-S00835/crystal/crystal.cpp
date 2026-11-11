#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int l=0,r=1;r<=n;r++){
		while(l<r&&a[r]*(r-l)-(s[r]-s[l])>m) l++;
		ans=max(ans,r-l);
	}
	cout<<ans;
}
