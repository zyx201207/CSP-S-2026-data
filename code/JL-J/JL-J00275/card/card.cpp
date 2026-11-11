#include<bits/stdc++.h>
using namespace std;
int n,m,x[100003],v[100003],z[10001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=0;i<n;i++)
	{
		memset(v,0,sizeof(v));
		int l=i;
		for(int j=i;j<n;j++)
		{
			if(!v[x[j]])
			{
				v[x[j]]=1;
			}
			else
			{
				l=j;
			}
		}
		
		for(int j=l;j<n;j++)
		{
			z[x[j]]++;
		}
	}
	cout<<z[1];
	for(int i=2;i<=m;i++)
	{
		cout<<" "<<z[i];
	}
	return 0;
}
