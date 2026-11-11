#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string t="";
	long long n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char s;
		cin>>a>>s;
		for(int j=1;j<=a;j++)
		{
			t+=s;
		}
	}
	long long U=t.size();
	for(int i=0;i<=U/2;i++)
	{
		if(t[i]!=t[U-i-1]&&i<=U-i-1) cnt++;
	}
	
	cout <<cnt;
	return 0;
	
}
