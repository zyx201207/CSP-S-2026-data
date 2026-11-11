#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m,a[200005];
    int b[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    if(m==1){sort(a,a+n+1);
    cout<<a[n-1];
	}
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			b[0]=max(max(i&j,j&i),b[0]);
		}
		cout<<b[0];
	}
	if(m==n-1)
	{
		for(int i=0;i<n;i++)
		{
		    b[i]=a[0];
			for(int j=0;j<n;j++)
			if(j!=i)
			b[i]=b[i]&a[j];
		}
		sort(b,b+n+1);
		cout<<b[n-1];
	}
	if(m==n)
	{
		b[0]=a[0];
		for(int i=1;i<n;i++)
		{
			b[0]=b[0]&a[i];
		}
		cout<<b[0];
	}
	return 0;
}