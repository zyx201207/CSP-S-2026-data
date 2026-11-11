#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXM=300005;
long long n,m;
long long a[MAXN],t[MAXM]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		string s;
		for(int j=i;j<=n;++j)
		{
			string t=to_string(a[j]);
			if(s.find(t)>s.size()) s+=t;
			else 
			{
				string k;
				for(int x=i;x<=i+s.find(t);++x)
				{
					k+=to_string(a[x]);
				}
				s=k;
			}
		}
		for(int y=0;y<s.size();++y)
		{
			t[s[y]-'0']++;
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}