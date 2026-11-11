#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,a[10000],l,r,k,t,m,b[10000],x;
string c,s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
			cin>>a[i];
			b[i]=b[i-1]+a[i];
	}
for(i=1;i<=n;i+=m)
{
	if(b[i]>x)
	x=b[i];
}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}