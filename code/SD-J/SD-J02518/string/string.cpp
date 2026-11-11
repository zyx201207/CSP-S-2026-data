#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			s+=b[i]; 
		}
	}
	int cnt=0;
	for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
} 

