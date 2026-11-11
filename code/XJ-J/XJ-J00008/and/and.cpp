#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,s,l,k,a[10000];
int main()
{
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=m;k++)
		{
			if(s<(s&a[k]))
			s=(s&a[k]);
		}
	}
	cout<<s;
	return 0;
}