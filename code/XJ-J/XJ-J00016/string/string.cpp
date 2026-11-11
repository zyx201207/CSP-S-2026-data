#include<bits/stdc++.h>
using namespace std;
long long int n,a,b[20005],q,num=0;
char c[20005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>c[i];
	}
	if(n%2==0)
	{
		n=n/2;
	}
	else
	{
		n=n/2+1;
	}
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			if(b[l]>b[r])
			{
				b[l]=b[l]-b[r];
				r=r-1;
				continue;
			}
			else if(b[l]<b[r])
			{
				b[r]=b[r]-b[l];
				l=l+1;
				continue;
			}
			else if(b[l]==b[r])
			{
				l=l+1;
				r=r-1;
				continue;
			}
		}
		else
		{
			if(b[l]>b[r])
			{
				
				b[l]=b[l]-b[r];
				num=num+b[r];
				r=r-1;
				continue;
			}
			if(b[l]<b[r])
			{
				
				b[r]=b[r]-b[l];
				num=num+b[l];
				l=l+1;
				continue;
			}
			if(b[l]==b[r])
			{
				l=l+1;
				r=r-1;
				num=num+b[l];
				continue;
			}
		}
	}
	cout<<num;
	return 0;
}
