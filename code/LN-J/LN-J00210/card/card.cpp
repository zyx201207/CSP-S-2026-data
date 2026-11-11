#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],w[300005];
bool v[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		 cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
