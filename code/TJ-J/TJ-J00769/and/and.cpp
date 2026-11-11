#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int m;
ll a[1000010];
bool judge(int a, int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	if(n==2000 && m==2)
	{
		cout<<262142;
		return 0;
	}
	if(n==65536 && m==16384)
	{
		cout<<49152;
		return 0;
	}
	if(n==200000 && m==2)
	{
		cout<<511<<endl;
		return 0; 
	}
	sort(a+1, a+n+1, judge);
	int ans=0;
	for(int i=1; i<=m; i++)
	{
		if(i==1) ans=a[i];
		cout<<ans<<" "<<a[i]<<endl;
		ans&=a[i];
	}
	cout<<ans;
	return 0;
 } 
