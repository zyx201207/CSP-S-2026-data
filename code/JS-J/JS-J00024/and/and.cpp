#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
