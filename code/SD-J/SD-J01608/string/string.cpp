#include<bits/stdc++.h>
using namespace std;
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool flag=1;
	bool fl=1;
	long long sum=0,x,p;
	int n;
	cin>>n;
	char c,k;
	string s="1";
	for (int i=1;i<=n;i++)
	{
		k=c;
		x=p;
		cin>>x>>c;
		if(k!=c && i!=1) flag=0;
		s.append(x,c);
	}
	if (flag)
	{
		cout<<0;
		return 0;
	}
	long long l=s.length();
	for (int i=1;i<(l/2);i++)
	{
		if (s[i]!=s[l-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
