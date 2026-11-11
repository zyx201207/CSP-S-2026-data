#include<iostream>
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
int n;
long long cnt;
int main()
{
	CLOSE
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
