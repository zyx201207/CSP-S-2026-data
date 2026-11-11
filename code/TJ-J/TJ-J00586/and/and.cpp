#include<bits/stdc++.h>
using namespace std;
long long a[20005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(n==m)
	{
		for(int i=1;i<=n;i++)
	    {
		    a[i+1]=(a[i+1]&a[i]);
	    }
	    cout<<a[n];
	    return 0;
	}
	else if(m==1)
	{
		cout<<0;
	}
	else if (m==2)
	{
		cout<<(a[1]&a[2]);
	}
	else
	{
		cout<<a[m];
	}
    return 0;
}
