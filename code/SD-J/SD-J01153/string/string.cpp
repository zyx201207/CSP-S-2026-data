#include<bits/stdc++.h>
using namespace std;
int n,x,k,p;
long long cnt=0;
char c;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		for(int j=1;j<=x;j++)
		{
			s+=c;
		}
	}
	k=s.size();
	p=k/2;
	for(int i=0;i<p;i++)
	{
		if(s[i]!=s[k-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
