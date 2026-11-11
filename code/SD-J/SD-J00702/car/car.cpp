#include<bits/stdc++.h>
using namespace std;
int n,m,a[510000],b[510000];
map<int,int> s;
int main()
{
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			j=s[a[j]];
		}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}
