#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
long long n,sum,l,r;
struct node{
	long long ch;
	string s;
};
node a[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].ch>>a[i].s;
	}
	l=1;
	r=n;
	while(l<=r)
	{
		if(a[l].s!=a[r].s)
		{
			if(a[l].ch<a[r].ch)
			{
				a[r].ch-=a[l].ch;
				sum+=a[l].ch;
				l++;
			}
			else if(a[l].ch==a[r].ch)
			{
				sum+=a[l].ch;
				l++;
				r--;
			}
			else if(a[l].ch>a[r].ch)
			{
				a[l].ch-=a[r].ch;
				sum+=a[r].ch;
				r--;
			}
		}
		else
		{
			if(a[l].ch<a[r].ch)
			{
				a[r].ch-=a[l].ch;
				l++;
			}
			else if(a[l].ch==a[r].ch)
			{
				l++;
				r--;
			}
			else if(a[l].ch>a[r].ch)
			{
				a[l].ch-=a[r].ch;
				r--;
			}
		}
		
	}
	cout<<sum<<endl; 
	return 0; 
}
