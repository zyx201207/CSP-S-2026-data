#include<bits/stdc++.h>
using namespace std; 
long long sum,n;
struct q
{
	long long x;
	char ans;
}a[210000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		long long x;
		char ch;
		cin>>x;
		cin>>ch;
		a[i].x=x,a[i].ans=ch; 
	}
	int ll=1,rr=n;
	long long l1=a[ll].x,r1=a[rr].x;
	while(ll<=rr)
	{
		if(l1>=r1) 
		{
			if(a[ll].ans!=a[rr].ans) sum+=r1;
			l1-=r1;
			rr--;
			r1=a[rr].x;
		}
		else
		{
			if(a[ll].ans!=a[rr].ans) sum+=l1;
			r1-=l1;
			ll++;
			l1=a[ll].x;
		}
	}
	cout<<sum;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
