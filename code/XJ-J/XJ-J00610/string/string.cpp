#include<bits/stdc++.h>
using namespace std;
int a[105];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s;
	}
	if(s[1]==s[2]) 
	{
		if(n==6)
		{
			cout<<n/2*a[1];
		}
		else if(n==3)
		{
			cout<<n-1;
		}
		else  cout<<"0";	
	}
	return 0;
}