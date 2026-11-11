#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,k,s=0;
	char x;
	string ch,ah;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m>>x;
		for(int j=0;j<m;j++)
		{
			ch=ch+x;
		}
	}
	for(int i=ch.size()-1;i>=0;i--)
	{
		ah=ah+ch[i];
	}
	k=ch.size()/2-1;
	for(int i=0;i<=k;i++)
	{
		if(ch[i]!=ah[i])
		{
			s++;
		}
	}
	cout<<s;
	return 0;
}
