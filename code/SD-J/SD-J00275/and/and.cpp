#include <bits/stdc++.h>
using namespace std;
const int MAXN=200000;
int a[MAXN+10];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,ans,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>=1;i--)
	{
		ans&=a[i];
		cnt++;
		if(cnt==m)
			break;
	}
	cout<<ans;
	return 0;
}
