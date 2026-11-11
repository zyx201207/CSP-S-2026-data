#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],pm[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//b[i]=a[i]+b[i-1];
	}
	int mx=-1;int r=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
	}
	for(int l=1;l<=n;l++)
	{
		while(r<=n)
		{
			int x=a[r]*(r-l)-(b[r-1]-b[l-1]);
			if(x>m)
			{
				mx=max(mx,r-l);
				//cout<<r<<' '<<l<<"\n";
				break;
			}
			r++;
		}
	}
	cout<<mx;
	return 0;
}