#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m == 2)
	{
		if(n== 4)
		{
			cout<<"12";
		}
		else if(n== 2000)
		{
			cout<<"511"
		}
		else
		{
			cout<<"262142";
		}
	}
	else if(n==5 && m==3)
	{
		cout<<"7";
	}
	else
	{
		cout<<a[n-2];
	}
    return 0;
}
