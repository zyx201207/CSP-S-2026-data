#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int a[maxn];
int n,m;
bool check(int d)
{
	int need=0;
	int mn=1e18+2;
	int want;
	for(int i=1;i<=n-d+1;i++)
	{
		want=a[i+d-1];
		for(int j=i;j<=i+d-1;j++)
		{
			need+=want-a[j];
		}
		mn=min(mn,need);
	}
//	cout<<d<<' '<<idi<<' '<<idj<<' '<<want<<' '<<need<<' ';
//	cout<<d<<' ';
//	cout<<mn<<'\n';
	return mn<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int mx=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
//	cout<<mx<<' '<<cnt<<' '<<mn<<'\n';
	int l=1,r=n;
	while(l+1<r)
	{
//		cout<<"gunmu";
		int mid=(l+r)/2;
		if(check(mid))	l=mid;
		else	r=mid-1;
	}
	cout<<l;
}
