#include<bits/stdc++.h>
using namespace std;
long long n;
long long x[200005];
string a[200005];
long long l,r; 
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
	}
	r=n;
	l=1;
	while(l!=r)
	{
		if(l>=r)
		{
			break;
		}
		if(x[l]==0)
		{
			l++;
		}
		if(x[r]==0)
		{
			r--;
		}
		if(a[l]!=a[r])
		{
			if(x[l]>=x[r])
			{
				cnt+=x[r];
				x[l]-=x[r];
				x[r]=0;
			}
			else if(x[l]<x[r])
			{
				cnt+=x[l];
				x[r]-=x[l];
				x[l]=0;
			}
		}
		else
		{
			if(x[l]>=x[r])
			{
				x[l]-=x[r];
				x[r]=0;
			}
			else if(x[l]<x[r])
			{
				x[r]-=x[l];
				x[l]=0;
			}
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
