#include<bits/stdc++.h>
using namespace std;

int n;
string s1,s2;
unordered_map<char,int>mp;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	int len=0;
	for(int i=1;i<=n;i++)
	{
		int l;
		char c;
		scanf("%d %c",&l,&c);
		len+=l;
		for(int j=1;j<=l;j++)s1+=c;
	}
	s2=s1;
	reverse(s2.begin(),s2.end());
	int cnt=0;
	for(int i=0;i<len/2;i++)
	{
		if(s1[i]!=s2[i])cnt++;
	}
	printf("%d\n",cnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
