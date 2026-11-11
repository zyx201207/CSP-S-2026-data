#include<bits/stdc++.h>
using namespace std;
char c[1000000];
string s;
int n,a[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n=1)
	{
		cout<<0;
		return 0;
	}
	for(int x=1;x<=n;x++)
	{
		cin>>a[x]>>c[x];
	    if(n=2)
		{
			cout<<min(a[1],a[2]);
			return 0;
		}
		s+=c[x]*a[x];
	}
	int l;
	int sum; 
	for(int i=1;i<=l/2;i++)
	  for(int j=l;j>=l/2+1;j--)
	  {
	  	if(s[i]!=s[j])
	  	  sum++;
	  }
	cout<<sum;
	return 0;
}
