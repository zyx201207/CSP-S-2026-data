#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0,j;
	long long k=0,i;
	char c;
	string s;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(j=1;j<=a;j++) s[++k]=c;
	}
	for(i=1;i<=k/2;i++)
	{
		if(s[i]!=s[k-i+1]) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
