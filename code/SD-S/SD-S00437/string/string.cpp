#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100000000+10;
char s[N];
void solve_problems()
{
	int n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++)
		{
			len++;
			s[len]=c;
		}
	}
	int cnt=0;
	for(int i=1,j=len;i<=j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	for(int t=1;t<=T;t++)
	{
		solve_problems();
	}
	return 0;
}
