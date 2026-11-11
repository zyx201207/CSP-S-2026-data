#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],mi=2147483647;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mi=min(mi,a[i]);
	}
	cout<<mi;
	return 0;
}
