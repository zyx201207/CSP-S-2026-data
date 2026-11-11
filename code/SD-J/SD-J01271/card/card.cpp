#include<bits/stdc++.h>
using namespace std;
long long n,m,b[300001];
long long a[500001];
string s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s.clear();
		for(int j=i;j<=n;j++)
		{
			s+=(a[j]+'0');
			for(int q=0;q<s.size()-1;q++)
			{
				if(s[q]==s[s.size()-1])
				{
					s.erase(q,s.size()-q-1);
					break;
				}
			}
		}
		for(int j=0;j<s.size();j++)
		{
			b[s[j]-'0']++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i]!=0)cout<<b[i]<<" ";
	}
	return 0;	
} 
