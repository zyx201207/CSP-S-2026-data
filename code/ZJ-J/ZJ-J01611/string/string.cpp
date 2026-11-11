#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
LL ans,s;
int n,a[N];
char c[N],sss[11111111];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],s+=a[i];
	int k=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]--)
		{
			sss[k]=c[i];
			k++;
		}
	}
	for(int i=1;i<=s/2;i++)
	{
		if(sss[i]!=sss[s+1-i])ans++;
	}
	cout<<ans;
	return 0;
} 
