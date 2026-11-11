#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll i,j,n,a[N],ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(i=1;i<=n/2;i++)
	{
  		if(c[i]!=c[n-i+1])ans+=max(a[i],a[n-i+1]);
	}
	cout<<ans;
	return 0;
}
