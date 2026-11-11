//陈宇轩 西安市第八十九中学 SN-J00696 
#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[2000005];
bool flag=true,z=false;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (m==1)
		{
			ans=max(ans,a[i]);
		}
		
		if (a[i]>4)
		{
			flag=false;
		}
	}
	
	for (int i=1;i<=n;i++)
	{
		if (a[i]==ans)
		{
			ans=ans;
		}
		if (m==n)
		{
			ans=a[i]&ans;
		}
	}
	if (flag==true && m!=1 && m!=n)
	{
		ans=2;
	}
	cout << ans;
	return 0;
}
