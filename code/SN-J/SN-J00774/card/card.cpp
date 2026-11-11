//SN-J00774 章梓煜 西安翱翔中学 
# include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10000005],b[10000005],c[10000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		b[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=m;j++)
		{
			if(b[i]==a[j])
			{
				c[i]++;
			}

		}
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
 


