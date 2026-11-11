#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+1;
int x[MAXN];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int y=1;y<=t;y++)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		cout<<n-3<<endl;
	}
	return 0;
}