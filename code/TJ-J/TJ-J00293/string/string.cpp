#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n,ans=0;
int c[200050];
char s[200050]; 
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>s[i];
	}
	for(int i=1,j=n;i<j;)
	{
		if(c[i]==0) i++;
		if(c[j]==0) j--;
		if(c[i]==c[j])
		{
			if(s[i]!=s[j]) ans+=c[j];
			c[j]=0;
			c[i]=0;
			continue;
		}
		else if(c[i]>c[j])
		{
			c[i]-=c[j];
			if(s[i]!=s[j]) ans+=c[j];
			c[j]=0;
			continue;
		}
		else if(c[i]<c[j])
		{
			c[j]-=c[i];
			if(s[i]!=s[j]) ans+=c[i];
			c[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
