#include<bits/stdc++.h>
using namespace std;
int n,i,j,x,sum,m;
string s,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>a;
		while(x--)
		{
			s=s+a;
			m++;
		}
	}
	m=s.size();
	for(i=0;i<m/2;i++)
	{
		if(s[i]!=s[m-1-i])
		{
			s[m-1-i]=s[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
