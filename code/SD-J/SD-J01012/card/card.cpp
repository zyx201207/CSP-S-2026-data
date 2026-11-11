#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],c[N];
bool b[N];
map<int,int> mp;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>0;i--)
	{
		if(!mp[a[i]])
		{
			mp[a[i]]=i;
		}
		else
		{
			int j=i+1;
			b[mp[a[i]]]=1;
			while(a[j]!=a[i])
			{
				b[j]=1;
				mp[a[j]]=0;
				j++;
			}
			mp[a[i]]=i;
		}
		for(int k=i;k<=n;k++)
		{
			if(b[k]==0)
			{
				c[a[k]]++;
				if(a[k]==3)
				{
					cout<<i<<" ";
				}
			}
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
//I AK CSP-J!!!

