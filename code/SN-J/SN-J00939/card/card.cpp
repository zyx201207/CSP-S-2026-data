#include<bits/stdc++.h>
using namespace std;
string a;
int d[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		a+=c;
	}
	int n1=n,k=1;
	while(n1--)
	{
		string s="";
		for(int i=k-1;i<n;i++)
		{
			int t=s.find(a[i]);
			if(t!=-1)
			{
				s.erase(t,i-t+1);
			}
			s+=a[i];
		}
		for(int i=0;i<s.size();i++)
		{
			d[s[i]-'0']++;
		}
		k++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
