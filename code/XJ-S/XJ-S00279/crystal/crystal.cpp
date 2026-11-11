#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n,m;
int a[N],u[N],ans;
long long t[N],d[N],q;
long long getlen(int l,int r)
{
	long long t = 0;
	for(int i = l;i <= r;i++)
	{
		t += abs(a[r] - a[i]);
	}
	return t;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}	
	if(n <= 5000)
	{
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(getlen(i,j) <= m)
			{					
				ans = max(ans,j - i + 1);	
			}
		}
	}
	}
	else
	{
		long long t = 0;
		for(int i = 1;i <= n;i++)
		{
			if(t + a[i] - a[1] <= m)
			{
				t += a[i] - a[1];
				ans = i;
			}
			else
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
