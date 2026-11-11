#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long q[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long cz=0;
    bool f=0;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		if(i==2)
		{
			cz=abs(a[i]-a[i-1]);
		}
		if(i>2)
		{
			if(cz!=abs(a[i]-a[i-1]))
			{
				f=1;
				cz=abs(a[i]-a[i-1]);
			}
		}
    }
    if(f==0)
    {
		//cout<<1;
		for(int i=1;i<=n;i++)
		{
			if(m<i*cz) 
			{
				cout<<i-1;
				return 0;
			}
		}
	}
    sort(a+1,a+1+n);
    a[n+1]=a[n];
    for(int i=1;i<=n;i++)
    {
		q[i+1]=q[i]+i*(a[i+1]-a[i]);
	}
	int x=0,ma=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(q[i]-(a[i]-a[j-1])*(j-1)<=m)
			{
				x=(i-j+1);
				ma=max(x,ma);
			}
		}
	}
	cout<<ma;
    return 0;
}
