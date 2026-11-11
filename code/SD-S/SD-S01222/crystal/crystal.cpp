#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],cf[N],l,r,maxn=1,sm;//sm为消耗的能量,而不是sm8888 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cf[i]=a[i]-a[i-1];
	}
	l=1;
	for(r=2;r<=n;r++)
	{
		sm+=(r-l)*cf[r];
		while(sm>m)
		{
			sm-=(a[r]-a[l]);
			l++;
		}
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
	
	return 0;
}//RP++
//luogu uid:1902351
