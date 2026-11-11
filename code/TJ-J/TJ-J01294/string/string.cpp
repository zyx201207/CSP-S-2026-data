#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct www{
	ll k;
	char s;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].k>>a[i].s;
	}
	int l=0,r=n-1;
	while(l<r)
	{
		if(a[l].s!=a[r].s)
		{
			if(a[l].k>a[r].k)
			{
				sum+=a[r].k;
				a[l].k-=a[r].k;
				r--;
			}
			else if(a[l].k<a[r].k)
			{
				sum+=a[l].k;
				a[r].k-=a[l].k;
				l++;
			}
			else
			{
				sum+=a[l].k;
				l++;r--;
			}
		}
		else
		{
			if(a[l].k>a[r].k)
			{
				a[l].k-=a[r].k;
				r--;
			}
			else if(a[l].k<a[r].k)
			{
				a[r].k-=a[l].k;
				l++;
			}
			else
			{
				l++;r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
