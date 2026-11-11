#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
char t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k>>t;
		for(int j=1;j<=k;j++)s+=t;
	}
	long long ans=0,h=s.size()-1;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[h])ans++;	
		h--;
	}
	cout<<ans;
	return 0;
}