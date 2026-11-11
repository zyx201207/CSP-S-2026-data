#include<bits/stdc++.h>
using namespace std;
struct nnn
{
	int x;
	char s;
}a[200860];
int main()
{ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].s;
	}
	int ans=0,sum=0;
	for(int i=1;i<=(n+1)/2;i++)
	{
		if(a[i].s!=a[n-i].s)
		{
			ans+=max(a[i].x,a[n-i].x);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
