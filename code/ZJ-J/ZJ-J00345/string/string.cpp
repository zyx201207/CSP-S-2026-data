#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct add
{
	int a;
	char c;
}d[N];
int n;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>d[i].a>>d[i].c;
	int l=1,r=n,x=d[1].a,y=d[n].a;
	for(;l<=r;)
	{
		if(l==r)
		break;
		if(d[l].c!=d[r].c)
		{
			if(x>y)
			{
				x-=y;
				ans+=y;
				r-=1;
				y=d[r].a;
			}
			else
			{
				if(x==y)
				{
					l+=1;
					r-=1;
					ans+=y;
					x=d[l].a;
					y=d[r].a;
				}
				else
				{
					y-=x;
					ans+=x;
					l+=1;
					x=d[l].a;
				}
			}
		}
		else
		{
			if(x>y)
			{
				x-=y;
				r-=1;
				y=d[r].a;
			}
			else
			{
				if(x==y)
				{
					l+=1;
					r-=1;
					x=d[l].a;
					y=d[r].a;
				}
				else
				{
					y-=x;
					l+=1;
					x=d[l].a;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
