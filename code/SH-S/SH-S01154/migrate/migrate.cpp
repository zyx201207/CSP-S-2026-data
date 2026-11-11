#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n[10010];
ll d[10010],x[10010][10010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j =1;j<=n[i];j++)
		{
			cin>>x[i][j];
		}
	}
	
	return 0;
}

