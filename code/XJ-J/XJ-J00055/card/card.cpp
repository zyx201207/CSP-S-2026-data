#include <bits/stdc++.h>;
using namespace std;
long long n,m,ans=0;
string a;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==m)
			{
				ans=a[i-1];
			}
		}
	}
	cout<<m<<" "<< ans<<" "<<n;
	return 0;
}
