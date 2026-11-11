#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,sum;
string b;
struct stu
{
	long long y;
	string r;
	long long g;
};
stu a[200005];
string er(long long x)
{
	string s="";
	while(x)
	{
		s=char(x%2)+s;
		x/=2;
	}
	return s;
}
long long bian(string s)
{
	long long sum_1=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]==1)
		{
			sum_1++;
		}
	}
	return sum_1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].y;
		a[i].r=er(a[i].y);
		a[i].g=bian(a[i].r);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i].g>a[j].g)
			{
				swap(a[i],a[j]);
			}
		}
	}
	sum=a[n].y;
	for(int i=n-1;i>n-m;i--)
	{
		sum=(sum&a[i].y);
	}
	cout<<sum;
	return 0;
}
