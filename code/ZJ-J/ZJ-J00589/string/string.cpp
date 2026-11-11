#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string c,s="";
long long m=0,ans=0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		m+=a[i];
		for (int j=1;j<=a[i];j++)
		{
			s=s+c;
		}
	}
	if (m%2==1)//o
	{
		for (int i=0;i<=m/2+1;i++)
		{
			int j=m-i-1;
			if (s[i]!=s[j]) ans++;
		}
	}
	else//j
	{
	    for (int i=0;i<=m/2;i++)
	    {
	    	int j=m-i-1;
	    	if (s[i]!=s[j]) ans++;
    	}
	}
	cout<<ans;
	
	return 0;
}
