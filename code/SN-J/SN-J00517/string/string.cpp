#include<bits/stdc++.h>
using namespace std;
struct stu
{
	long long a1;
	char c;
};
stu a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].a1>>a[i].c;
	}
	long long l=1,r=n;
	while(l<r)
	{
		if(a[l].a1>a[r].a1)
		{
			if(a[l].c!=a[r].c)
			{
				sum+=a[r].a1;
			}
			a[l].a1-=a[r].a1;
			r--;
		}
		else if(a[l].a1<a[r].a1)
		{
			if(a[l].c!=a[r].c)
			{
				sum+=a[l].a1;
			}
			a[r].a1-=a[l].a1;
			l++;
		}
		else
		{
			if(a[l].c!=a[r].c)
			{
				sum+=a[l].a1;
			}
			a[l].a1=0;
			a[r].a1=0;
			l++;
			r++;
		}
	}
	cout<<sum;
	return 0;
}

