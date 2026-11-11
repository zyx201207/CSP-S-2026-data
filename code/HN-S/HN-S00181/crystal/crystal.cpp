#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],pre[N],b[N],c[N];
bool check(int j,int i)
{
	return ((i-j+1)*a[i]-(pre[i]-pre[j-1]))<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];  
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i]; 
	}
	int maxl=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(check(mid,i))
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
			maxl=max(maxl,i-r+1);
		}
	}
	cout<<maxl;
	return 0;
}
