#include<bits/stdc++.h>
using namespace std;
int a,cnt,n;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	int len=s.length();
	for(int i=0;i*2<len;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
