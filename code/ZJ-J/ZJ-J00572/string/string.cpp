#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long l=1,r=n,restl=a[1],restr=a[n],num=0;
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			if(restl>restr)
			{
				num+=restr;
				restl-=restr;
				r--;
				restr=a[r];
			}
			else if(restl<restr)
			{
				num+=restl;
				restr-=restl;
				l++;
				restl=a[l];
			}
			else
			{
				num+=restl;
				r--;
				l++;
				restl=a[l];
				restr=a[r];
			}
		}
		else
		{
			if(restl>restr)
			{
				restl-=restr;
				r--;
				restr=a[r];
			}
			else if(restl<restr)
			{
				restr-=restl;
				l++;
				restl=a[l];
			}
			else
			{
				r--;
				l++;
				restl=a[l];
				restr=a[r];
			}
		}
	}
	cout<<num;
	return 0;
}