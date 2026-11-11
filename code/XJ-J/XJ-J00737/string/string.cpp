#include<bits/stdc++.h>
using namespace std;
long long int i,n,a,j,k,ans,f,h;
string s={0};
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(j=1;j<=a;j++)
		{
			if(c.size()-1>1)
			for(h=1;h<=c.size()-1;h++)
			s[++k]=c[h];
			if(c.size()-1==1)
			s[++k]=c[1];
		}
	}
	for(i=1,j=k;i!=j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			s[j]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}