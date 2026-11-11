#include<bits/stdc++.h>
using namespace std;
long long m,n,a[100000005],x=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=x)
			x=a[i];
		}
		cout<<x;
	}
   return 0;
}
