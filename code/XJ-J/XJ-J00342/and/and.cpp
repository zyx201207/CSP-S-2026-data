#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],maxa=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxa)
		{
			maxa=a[i];
		}
		
	}
	if(m==2){
	
	
	    int maxn=a[1]&a[2];
	    for(int i=1;i<n;i++)
	    {
		    for(int j=i+1;j<=n;j++)
		    {
			    if(a[i]&a[j]>maxn)
			    {
				    maxn=a[i]&a[j];
			    }
		    }
	    }
	    cout<<maxn;
    }
    else if(m==1)
    {
	    cout<<maxa;
	}
	else if(m==n)
	{
		int c=a[1];
		for(int i=2;i<=n;i++)
		{
			c&=a[i];
		}
		cout<<c;
	}
	return 0;
}