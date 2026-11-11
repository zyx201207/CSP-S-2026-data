#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,to[N],a;
long long d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int sum=0;
		cin>>n>>d;
		memset(x,0,sizeof(x));
		memset(to,0,sizeof(to));
		a=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
