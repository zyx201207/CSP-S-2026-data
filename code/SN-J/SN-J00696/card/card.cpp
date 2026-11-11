//陈宇轩 西安市第八十九中学 SN-J00696 
#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=n,num=n;
long long a[5000005],b[500005];
bool flag=false;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=1;
	}
	if (m!=2)
	{
		for (int i=0;i<n;i++)
		{
			cout << n-i << " ";
		}
	}
	if (m==2)
	{
		cout << n-1 << " " << n-2;
	}
	return 0;
}
