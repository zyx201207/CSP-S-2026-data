#include <bits/stdc++.h>
using namespace std;
char c,s[1000000005],e=1;
long long n,a,sum=1,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
		      s[sum]=c;
			  //cout<<s[sum]<<endl;
		      if(i!=n) sum++;
		}
	}
	while(e<=sum/2)
	{
		if(s[e]!=s[sum+1-e]) ans++;
		e++;
	}
     cout<<ans;
	return 0;
}