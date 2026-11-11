#include<bits/stdc++.h>
using namespace std;
struct aa
{
	int s;
	char x;
};
aa a[200009];
int i,l,r,n,l1,r1;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].x;	
	}
	l=1;
	r=n;
	l1=a[1].s;
	r1=a[r].s;
	while(l<=r)
	{
		if(a[l].x!=a[r].x)
		{
			sum+=min(l1,r1);
		}
		if(l1>r1)
		{
			l1-=r1;
			r--;
			r1=a[r].s;
		}
		else if(r1>l1)
		{
			r1-=l1;
			l++;
			l1=a[l].s;
		}
		else
		{
			l++;
			r--;
			l1=a[l].s;
			r1=a[r].s;
		}
	}
	cout<<sum;
	return 0;
}
