#include<bits/stdc++.h>
using namespace std;
int a[300010],b[500010];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		a[i+1]=i+1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}

