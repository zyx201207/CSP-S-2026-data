#include<bits/stdc++.h>
using namespace std;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		while(a--)
		{
			s+=c;
		}
	}
	int sum=0,cnt=s.size();
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[--cnt])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
