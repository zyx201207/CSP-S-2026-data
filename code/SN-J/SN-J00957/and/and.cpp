#include <bits/stdc++.h>
using namespace std;
long long n,a[1001],m,maxx,mn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0; 
	}
	if(m==n)
	{
		mn=a[1];
		for(int i=1;i<=n;i++)
		{
			mn=mn&a[i];
		}
		cout<<mn<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
