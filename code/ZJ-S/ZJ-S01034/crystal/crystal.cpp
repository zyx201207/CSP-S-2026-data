//Backward, go backward, go back to the -
//- Petrichor -
//- I will pray forever even if it never ends. -
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int b[N];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(b[i]-b[i-x]+m>=a[i]*x)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	int l=0,r=N;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
//freopen("crystal.in","w",stdout);
//freopen("crystal.ans","r",stdin);
//648647291436