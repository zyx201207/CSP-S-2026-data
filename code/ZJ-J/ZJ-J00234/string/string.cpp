#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	int x=a[1],y=a[n];//l还有x r还有y
	int ans=0;
	while((l<r)||(l==r&&x+y<=a[l]))
	{
		if(x>=y)
		{
			if(c[l]!=c[r])
			{
				ans+=y;
			}
			r--;
			x-=y;
			y=a[r];
		}
		else
		{
			if(c[l]!=c[r])
			{
				ans+=x;
			}
			l++;
			y-=x;
			x=a[l];
		}
	}
	cout<<ans;
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
