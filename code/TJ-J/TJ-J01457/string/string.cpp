#include<bits/stdc++.h> 
using namespace std;
int n;
int a;
char c[200005];
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		cin>>c[i];
		for(int j=1;j<=a;j++)
		{
			s+=c[i];
		}
	}
	string s0;
	for(int i=0;i<=s.size();i++)
	{
		s0[i]=s[s.size()-1-i];
	}
	long long cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s0[i])
		{
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
}
