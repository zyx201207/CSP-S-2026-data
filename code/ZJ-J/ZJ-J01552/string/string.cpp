#include<bits/stdc++.h>
using namespace std;
string s;
int n,a,ans,i,j;
char c;
int x(int m)
{
	if(m%2==1)return m/2;
	else return m/2-1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(j=1;j<=a;j++)s=s+c;
	}
	for(i=0;i<=x(s.size());i++)
	{
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
