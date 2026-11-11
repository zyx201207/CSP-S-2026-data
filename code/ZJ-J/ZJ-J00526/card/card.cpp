#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+200;
int a[N],m,mp[N];
int n,cnt,flaga=1;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) flaga=0;
	}
	if(flaga||m>=n)
	{
		for(int i=1;i<=m;i++)
			cout<<n-i+1<<" ";
		return 0;
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(m==2)
	{
		cout<<n<<" "<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		bool b[N]={0};
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]) 
				for(int k=j-1;;k--)
				{
					b[a[k]]=0;
					if(a[k]==a[j]) break;
				}
			b[a[j]]=1;
		}
		for(int i=1;i<=m;i++)
			mp[i]+=b[i];
	}
	for(int i=1;i<=m;i++)
		cout<<mp[i]<<" ";
	return 0;
}
