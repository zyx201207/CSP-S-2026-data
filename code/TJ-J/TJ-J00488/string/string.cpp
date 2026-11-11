#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,len=0;
	string s="";
	int a;
	char c;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> c;
		for(int j=0;j<a;j++)
		{
			s += c;
		}
		len += a;
	}
	if(len<1000000000)
	{
		
		for(int i=0;i<len/2;i++)
		{
			if(s[i]!=s[len-i-1])
			{
				cnt ++;
			}
		}
		cout << cnt;
	}
	else
	{
		cout << len/2;
	}
	return 0;
}
