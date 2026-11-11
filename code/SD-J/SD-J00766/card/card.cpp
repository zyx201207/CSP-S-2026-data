#include<bits/stdc++.h>
using namespace std;
int n,m,b[300005];
char a[500005];
string h;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	string s,q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s.find(a[j])==-1)
			{
				s+=a[j];
			}
			else
			{
				q=s[0];
				for(int k=1;k<=s.find(a[j]);k++)
				{
					q+=s[k];
				}
				s=q;
			}
		}
		for(int k=0;k<s.size();k++)
		{
			b[s[k]-'0']++;
		}
		s=h;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
} 
