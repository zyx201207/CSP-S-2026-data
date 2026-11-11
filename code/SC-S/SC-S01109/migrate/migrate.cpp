#include<bits/stdc++.h>
using namespace std;
int n[10000000];
int d[10000000];
long long x[10000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;1<=t;i++)
	{
		cin>>n[i]>>d[i];
		cin>>x[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}