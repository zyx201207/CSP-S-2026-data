#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
const int N=2e6+10;
int n,m,ans=-100000;
int a[N];
bool cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}
	if(m==2)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;++i)
		{
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}


