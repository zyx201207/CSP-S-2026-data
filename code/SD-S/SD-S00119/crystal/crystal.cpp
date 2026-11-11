#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
const int N=5e5+5;
int n,m,ans,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int r=1,l=1;r<=n;r++){
		while(a[r]*(r-l+1)-(s[r]-s[l-1])>m)l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}

