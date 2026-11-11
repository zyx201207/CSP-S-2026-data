#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxn;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	maxn=a[1];
	for(int i=1;i<=m;i++)
	{
		maxn=maxn&a[i];
	}
	cout<<maxn;
	return 0;
} 
