#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long b=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;	
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&m,&c);
		for(int j=1;j<=m;j++)
		{
			s+=c;
		}
	}
	int a=s.size();
	int j=0;
	for(int i=a-1;i>a/2;i--)
	{
		
		if(s[i]!=s[j])
		{
			b++;
		}
		j++;
	}
	cout<<b;
	return 0;
}
