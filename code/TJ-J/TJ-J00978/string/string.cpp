#include<bits/stdc++.h>
using namespace std;
int n;
string s1;
int r,l;
int x;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>s;
		for(int j=1;j<=x;j++)
		{
			s1+=s;
		}
	}
	int len=s1.size();
	int cnt=0;
	for(int i=1;i<=len/2;i++)
	{
		if(s1[i-1]!=s1[len-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
