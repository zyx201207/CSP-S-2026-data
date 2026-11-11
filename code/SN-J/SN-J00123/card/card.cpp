#include<bits/stdc++.h>
using namespace std;
string s;
int a[500005],xxr[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;

	string s,b[n];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			s+=b[j];
			for(int k=0;k<n;k++)
			{
				if(s[j]==s[k])
				{
					for(int q=k;q<n;q++)
					{
						s[q]=' ';
					}
				} 
			}
			//cout<<s<<" "<<endl;
		}
	}
	int len=s.length();
	for(int j=0;j<len;j++)
	{
		xxr[s[j]]++;
	}
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<xxr[s[j]]<<" ";
		}
	}
	return 0;
}
