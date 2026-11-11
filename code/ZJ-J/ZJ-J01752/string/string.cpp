#include<bits/stdc++.h>
using namespace std;
int ans,n,a,len;
char c[200100];
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c[i];
		for(int j=1;j<=a;j++)
		{
			s=s+c[i];
		}
		len+=a;
	}
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
	
}
