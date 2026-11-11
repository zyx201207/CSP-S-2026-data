#include <bits/stdc++.h>
using namespace std;
string  s;
int  cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int  t;
	cin>>t;
	while(t--)
	{
		int  n;
		char  m;
		cin>>n>>m;
		for(int  i=1;i<=n;i++)
		{
			s.push_back(m);
		}
	}
	for(int  i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}
