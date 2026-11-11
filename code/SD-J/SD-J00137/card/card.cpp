#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cout<<i<<" ";
	return 0;
}
