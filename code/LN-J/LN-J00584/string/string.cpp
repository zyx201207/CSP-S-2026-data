#include<bits/stdc++.h>
using namespace std;

int n;
string s;
string ss=s;
long long ans;
int j;
int len=ss.length();

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int ai;
		cin>>ai;
		char cn;
		cin>>cn;
		for(int i=1;i<=cn;i++)
		{
			s[i]=ai;
		}
	}
	ss=s;
	cout<<s<<endl;
	len=ss.length();
	for(int i=1;i<len;i++)
	{
		j=len-i;
		if(ss[i]!=s[i])
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
