#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt,l;
string s;
char y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	l=s.size();
	for(int i=0;i<=l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
//			cout<<i<<" "<<s[i]<<" "<<s[l-i]<<endl;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
