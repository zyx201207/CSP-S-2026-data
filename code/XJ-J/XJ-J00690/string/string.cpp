#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,a[N],l,r,sum,flag;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<=r)
	{
		flag=min(a[l],a[r]);
		if(c[l]!=c[r])
		{
			sum+=flag;
		}
		a[l]-=flag;
		a[r]-=flag;
		if(a[l]<=0)
		{
			l++;
		}
		if(a[r]<=0)
		{
			r--;
		}
	}
	cout<<sum;
	return 0;
}
