#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int t[N],n,m,a[N],ans=-1e9,s[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{	
		t[a[i]]++;	
		if(t[a[i]]>=2)
		{
			for(int j=i;j>=1;j--)
			{
				t[a[j]]=0;
			}
			s[a[i]]++;
		}
		else
		{
			for(int j=1;j<=i;j++)
			{
				if(t[a[j]]==1)
				s[a[j]]++;
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<s[a[j]]<<' ';
	}
}