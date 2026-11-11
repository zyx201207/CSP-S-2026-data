#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++)
		ans&=a[i];
	cout<<ans;
	return 0;
}
