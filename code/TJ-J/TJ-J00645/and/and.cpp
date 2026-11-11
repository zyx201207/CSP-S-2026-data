#include<bits/stdc++.h>
using namespace std;
int n,i=0;
int n,m;
int a[500005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<max(a[1]&&a[2],a[2]&&a[3]);
	cout<<1;
	return 0;
}

