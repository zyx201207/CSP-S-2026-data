#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[10005],b[10005];
	int n,d,f,cnt=0,h=0,t;
	long long qw=1;
	cin>>n>>f;
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		while(d!=0)
		{
			cnt++;
			a[cnt]=d%2;
			d/=2;
			b[cnt]=d%2;
			d/=2;
		}
		for(int i=1;i<cnt;i++ )
		{
			if(a[i]==b[i])
			{
				h+=qw;		
				qw*=2;
			}
		}
		if(h>cnt)
		{
			t=h;
			h=0;
		}
		else	h=0;
	}
	cout<<cnt;
	return 0;
}
