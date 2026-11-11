#include<bits/stdc++.h>
using namespace std;
const int N=5e5+15;
#define int long long
int n,m;
int a[N];
int s[N];
int cnt,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++)
	{
		int cur=a[i]*(i-j+1);
		while(j<=i && cur-(s[i]-s[j-1])>m)
		{
			j++;
			cur-=a[i];
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}