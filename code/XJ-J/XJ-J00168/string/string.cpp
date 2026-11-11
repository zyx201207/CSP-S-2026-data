#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	ios::sync_with_stdio(false);
	int n,a[100005];
	char b[100005];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	string s1;
	for(int i=s.size();i>=1;i--)
	{
		s1+=s[i];
	}
	int num=0;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			num++;
		}
	}
	cout<<num;
}
