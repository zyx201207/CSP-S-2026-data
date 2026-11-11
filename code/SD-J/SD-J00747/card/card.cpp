#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],t[1000005];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<(t[i]*m+1)/2<<" ";
	}
	return 0;
}
