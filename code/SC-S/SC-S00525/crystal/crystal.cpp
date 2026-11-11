#include<iostream>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<deque>
#include<set>
#include<cstring>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+5;
const long long MAXN=0x3f3f3f3f3f3f3f3f;
long long n,m,a[N],need[N],ans=0;
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int r=1;r<=n;r++)
	{
		long long tar=a[r];
		for(int i=1;i<=n;i++)
		{
			if(a[i]>tar) need[i]=MAXN;
			else need[i]=tar-a[i];
		}
		sort(need+1,need+n+1,cmp);
		long long res=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(res+need[i]<=m) res+=need[i],cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	return 0;
}