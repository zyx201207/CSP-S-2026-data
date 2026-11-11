#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long x[2000005];
long long cha;
long long jieguo;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		cha=x[2]-x[1];
		
		if(d<cha)
		{
			cout<<0<<endl;
			continue;
		}
		jieguo=d/cha*2;
		cout<<jieguo-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
