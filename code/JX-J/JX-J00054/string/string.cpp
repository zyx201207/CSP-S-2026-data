#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,sum=0;
long long a[MAXN];
char c[MAXN];
long long top,plat=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	top=n;
	while(plat<top)
	{
		if(c[top]==c[plat])
		{
			if(a[top]>a[plat])
			{
				a[top]-=a[plat];
				plat++;
			}
			else if(a[top]==a[plat])
			{
				top--;
				plat++;
			}
			else
			{
				a[plat]-=a[top];
				top--;
			}
		}
		else
		{
			if(a[top]>a[plat])
			{
				a[top]-=a[plat];
				sum+=a[plat];
				plat++;
			}
			else if(a[top]==a[plat])
			{
				sum+=a[plat];
				top--;
				plat++;
			}
			else
			{
				sum+=a[top];
				a[plat]-=a[top];
				top--;
			}
		}
	}
	cout<<sum;
	return 0;
}
