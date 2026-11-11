#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010]={0};
char b[200010]={0};
string s="";
int cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++)
		{
			s=s+b[i];
		}
	}
	
	int l=s.size();
	for(int i=0;i<=l/2;i++)
	{
		if(l-i-1<=i)break;
		if(s[i]!=s[l-i-1])cnt++;
	}
	cout<<cnt;
	
	
	return 0;
}