#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=5e5+5;
int n,a[N*2],m;
bool cmp(int x,int y)
{
	return x<y;
}
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=x;i++)cnt+=a[x]-a[i];
//	cout<<x<<" "<<mid<<" "<<cnt<<'\n';
	if(cnt<=m)return true;
	for(int i=x+1;i<=n;i++)
	{
		cnt=cnt-(a[i-1]-a[i-x]);
		cnt=cnt+(a[i]-a[i-1])*(x-1);
		if(cnt<=m)return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
 }

