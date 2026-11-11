#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1000;
long long n,a[N],l,r,cnt,d;
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	l=1;
	r=n;
	while(l<r)
	{
		d=min(a[l],a[r]);
		if(b[l]==b[r])
		{
			a[l]-=d;
			a[r]-=d;
		}
		else
		{
			cnt+=d;
			a[l]-=d;
			a[r]-=d;
		}
		if(a[l]==0)
		{
			l+=1;
		}
		if(a[r]==0)
		{
			r-=1;
		}
		if(l==r)
		{
			break;
		}
	}
	cout<<cnt;
	return 0;
}
