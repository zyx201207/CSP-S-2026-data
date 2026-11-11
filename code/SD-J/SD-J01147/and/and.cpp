#include <bits/stdc++.h>
using namespace std;
const int mn=2*1e5+5;
long long a[mn];
int n,m;long long maxx=-1e9,ans=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//草没看见m
	//dfs吗 早知道认真学了呜呜呜呜呜呜呜
	//应该能省二，暴力吧，省一什么的不重要 
	//25pts
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++) maxx=max(a[i],maxx);
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		  for(int j=i+1;j<=n;j++)
		    maxx=max(maxx,a[i]&a[j]);
	}
	if(m==n)
	{
		maxx=a[1];
		for(int i=2;i<=n;i++) maxx&=a[i];
	}
	cout<<maxx;
	return 0;
}
