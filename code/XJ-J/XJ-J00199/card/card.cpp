#include<bits/stdc++.h>
using namespace std;
char arr[500005];
int t[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	string s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s.find(arr[j])!=-1)
			{
				s.erase(s.find(arr[j]),s.size());
			}
			s+=arr[j];
		}
		for(int k=0;k<s.size();k++)
		{
			t[s[k]-'0']++;
		}
		s="";
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	
	return 0;
} 
