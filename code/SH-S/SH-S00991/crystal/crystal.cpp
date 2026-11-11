#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,ans,a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<i&&a[i]*(i-j+1)-(s[i]-s[j-1])>m)j++;
		ans=max(ans,(ll)i-j+1);
	}
	cout<<ans;
	return 0;
}
