#include<bits/stdc++.h>
using namespace std;
int x[10000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<n<<' ';
	}
	cout<<'\n';
	return 0;
}
