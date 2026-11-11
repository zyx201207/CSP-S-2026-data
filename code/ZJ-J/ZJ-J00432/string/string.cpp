#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s;
void f(string s)
{
	for(long long i=1;i<=(s.size()+1)/2;++i)
	{
		if(s[i]==s[n-i+1])continue;
		else cnt++;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=1;i<=a;++i)
		{
			s+=c;
		}
	}
	f(s);
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
