#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],c[N];
struct node
{
	int id,ch;
}b[N];
bool cmp1(int x,int y)
{
	return x<y;
}
bool cmp2(node a,node b)
{
	return a.ch<b.ch;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	sort(a+1,a+n+1,cmp1);
	int mid=a[n/2+1];
	for(int i=1;i<=n;i++)
	{
		b[i].ch=abs(mid-a[i]);
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp2);
	int cnt=0;
	int sumch=0;
	for(int i=1;i<=n;i++)
	{
		if(sumch+b[i].ch<=m&&b[i].id<=mid)
		{
			sumch+=b[i].ch;
			cnt++;
		}
		if(sumch+b[i].ch<=m&&b[i].id>=mid)
		{
			sumch+=b[i].ch;
			mid=a[b[i].id];
			cnt++;
		}
		if(sumch==m||cnt==n)
		{
			break;
		}
	}
	cout<<cnt;
	return 0;
}