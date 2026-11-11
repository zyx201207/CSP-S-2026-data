#include<bits/stdc++.h>
using namespace std;
string s1,s2;
const int N=2e6+5;
long long int n,m,t[N],a[N],sum,maxn=-2e9,cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>s2;
		for(int i=1;i<=m;i++)
		s1+=s2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(s1[i]!=s1[j])
			{
				cnt++;
			}
		}
	}
	cout<<cnt/2;
	return 0;
}