#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int n,a,cnt,l;
char c;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a>>c;
		for(int j=1; j<=a; j++)
		{
			s+=c;
		}
	}
	l=s.size();
	for(int i=0; i<l/2+1; i++)
	{
		if(s[i]!=s[l-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
