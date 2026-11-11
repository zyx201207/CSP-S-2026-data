#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],h,t,ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	h=1;
	t=n;
	while(h<t)
	{
		if(c[h]!=c[t])
		{
			if(a[h]<=a[t])
			{
				ans+=a[h];
				a[t]-=a[h];
				a[h]=0;
				h++;
			}
			else
			{
				ans+=a[t];
				a[h]-=a[t];
				a[t]=0;
				t--;
			}
		}
		else
		{
			if(a[h]<=a[t])
			{
				a[t]-=a[h];
				a[h]=0;
				h++;
			}
			else
			{
				a[h]-=a[t];
				a[t]=0;
				t--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
