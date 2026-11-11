#include<bits/stdc++.h>
using namespace std;
long long int a,n,c,i,j,ans=0,l,r,k=0;
char b[1000005],e[1000005],f[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>e[i]>>f[i];
		if(n==1)
		{
			cout<<0;
			return 0;
		}
		for(j=k+1;j<=e[i]+k;j++)
		{
			b[j]=f[i];
			k=j;
		}
	}
	l=1;r=k;
	while(l==r)
	{
		if(b[l]!=b[r])
		ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}