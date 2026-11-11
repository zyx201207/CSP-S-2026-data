#include <bits/stdc++.h>
using namespace std;
unsigned long long a,ans,sum,l,r;
char c;
string s;
int main()
{freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		ans+=a;
		for(int j=1;j<=a;j++)
		{
	    	s+=c;
		}
	}
	l=0;
	r=s.size()-1;
for(int i=0;i<ans/2+1;i++)
{
	if(s[l]!=s[r]&&l<=r)
	{
	sum++;
	}
	l++;
	r--;
}
cout<<sum;
return 0;
}

