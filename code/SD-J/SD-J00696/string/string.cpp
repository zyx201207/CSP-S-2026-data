#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans,x;
char s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>s;
		for(int j=x+1;j<=x+m;j++)
		{
			a[j]=s-'a';
		}
		x+=m;
	}
	for(int i=1;i<=x/2;i++)
	{
		if(a[i]!=a[x+1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
//Trick||Treat!
//24474
