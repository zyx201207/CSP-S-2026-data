#include<bits/stdc++.h>
using namespace std;
char z[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n,s,i,j,m=1,ans=0;
	char a;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		cin>>a;
		for(j=m;j<=m+s-1;j++)
		{
			z[j]=a;
		}
		m+=s;
	}
	for(i=1;i<=(m-1)/2;i++)
	{
		if(z[i]!=z[m-i]) ans++;
	}
	cout<<ans;
	return 0;
}
