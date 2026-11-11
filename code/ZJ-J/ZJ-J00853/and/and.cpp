#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,x,t,ma,ans,f[200100],a[200100],s,j,g[50];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=30;i>=0;i--){
		ans=0;
		for(j=1;j<=n;j++)
			if((a[j]>>i)%2&&f[j]==0)
				ans++;
		if(ans<m)continue;
		for(j=1;j<=n;j++)
			if(!((a[j]>>i)%2))f[j]=1;
		g[i]=1;
	}
	for(i=30;i>=0;i--)
		s=s*2+g[i];
	cout<<s;
	return 0;
}