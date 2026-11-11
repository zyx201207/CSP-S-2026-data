#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=1;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string a;
		cin>>x>>a;
		for(int j=1;j<=x;j++)
		{
			s+=a;
		}
	}
	
	int y=s.size();
	char q=s[0];
	for(int i=1;i<y;i++)
	{
		if(s[i]==q)
		cnt=0;
		else
		{
			cnt=1;
			break;
		}
	}
	
	if(cnt==0)
	cout<<0;
	else
	cout<<y/2;
	return 0;
}
