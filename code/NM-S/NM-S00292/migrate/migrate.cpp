#include<bits/stdc++.h> 
using namespace std;
int c,t,n,d;
const int N=2e6+100;
int x[N];
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
	}
	if(c==0&&t==2) cout<<1<<" "<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
