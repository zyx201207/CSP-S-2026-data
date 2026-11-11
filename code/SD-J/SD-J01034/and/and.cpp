#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],dp[200010],maxx;
bool cmp(long long x,long long y)
{
	return x>y;
}

int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;++i)
{
	scanf("%d",&a[i]);
}
sort(a+1,a+1+n,cmp);maxx=a[1];
for(int i=2;i<=m;++i)
{
	maxx&=a[i];
}cout<<maxx;
return 0;
}

