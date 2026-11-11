#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans,cj[N];
int main()
{
	/*
	5 5
	1 2 4 8 9
	
	5 8
	-3 -1 2 2 7
	*/
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long jian=m;
		for(int j=1;j<=i;j++)
		{
//			cj[j]=abs(a[i]-a[j]);
			cj[j]=cj[j-1]+(a[i]-a[j]);
		}
		sort(cj+1,cj+i+1);
		long long f=upper_bound(cj+1,cj+i+1,jian)-cj-1;
		ans=max(ans,f);
	}
	cout<<ans;
	return 0;
}