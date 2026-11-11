#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int s=a[n];
	for(int i=1;i<=m-1;i++)
	{
		s&=a[n-i];
	}
	cout<<s;
	return 0;
}
