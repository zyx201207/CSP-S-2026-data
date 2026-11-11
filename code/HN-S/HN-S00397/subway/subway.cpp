#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500],a[5000],t[5000],k[500],s[2000],e[2000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=p;i++)cout<<t[1]*n+w[1]*n<<endl;
	return 0;
}
