#include<bits/stdc++.h>
using namespace std;
long long m,n,cnt=0;
string s,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>m>>s;
		c+=s;
	}
	long long l=c.size()-1;
	for(int i=0;i<=l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			cnt++;
		}
	} 
	cout<<cnt;
	return 0;
}
