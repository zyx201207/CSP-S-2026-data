#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int t[300010];
void solve(int x,int n)
{
	string s="";
	for(int i=x;i<=n;i++)
	{
		char f=char(a[i]+'0');
		for(int j=0;j<s.size();j++)
		{
			if(s[j]==f)
			{
				s.erase(j,s.size()-j);
			}
		}
		s+=f;
	}
	for(int j=0;j<s.size();j++)
	{
		t[int(s[j]-'0')]++;
	}
}
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
		solve(i,n);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
