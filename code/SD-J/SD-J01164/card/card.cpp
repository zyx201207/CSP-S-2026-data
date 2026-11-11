#include<bits/stdc++.h>
using namespace std;
int a[10001],s[10001],n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
	}
	s[a[n]]++;
	for(int i=1;i<=m;i++) cout<<s[m]<<" ";
	return 0;
}
