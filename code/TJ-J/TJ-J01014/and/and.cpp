#include<bits/stdc++.h>
using namespace std;
int a[1000000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int maxn=-1;
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
	}
}
