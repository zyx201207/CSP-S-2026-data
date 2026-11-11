#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5e5+5;
int n,m,cnt=0,l=1,ans=0; 
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cnt+=(i-l)*(a[i]-a[i-1]);
		while(cnt>m)
		{
			cnt-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
} 