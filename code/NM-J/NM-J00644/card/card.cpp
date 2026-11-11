#include<bits/stdc++.h>
using namespace std;
int t[300001],s[500001],h[100001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n,i,m,j,k,y=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			h[s[j]]=0;
			y=1;
		}
		for(j=i;j<=n;j++)
		{
			t[s[j]]++;
			h[s[j]]++;
			if(h[s[j]]>=2)
			{
				for(k=y;k<=j-1;k++)
				{
					t[s[k]]--;
					h[s[k]]--;
				}
				y=j;
				h[s[j]]--;
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
