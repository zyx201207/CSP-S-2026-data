#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],ans=0;
bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(sqrt(a[i]+1)*sqrt(a[i]+1)==a[i]+1)
		ans=max(ans,a[i]);
	}
	if(ans==0)ans=2147483647;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
 } 
