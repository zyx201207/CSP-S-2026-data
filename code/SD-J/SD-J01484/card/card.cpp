#include<bits/stdc++.h>
using namespace std;
string s1,s2;
const int MAXN=3e5+5;
int b[MAXN];
int n,m;
const int maxn=2e5+5;
int a[maxn];
int main(){
	freopen("card.in.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int len=s1.find(a[j]+'0');
			if(len==-1)
			{
				s1+=a[j]+'0';
				s2=s1;
			}
			else
			{
				s1="";
				for(int k=0;k<=len;k++)
				{
					s1+=s2[k];
				}
				s2=s1;
			}
		}
		for(int j=0;j<s1.size();j++)
		{
			b[s1[j]-'0']++;
		}
		s1="";
		s2="";
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
