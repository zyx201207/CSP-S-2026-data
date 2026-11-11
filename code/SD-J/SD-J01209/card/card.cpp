#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int s[500005];
int ans[300005];
int book[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int Npst=0;
	if(n<=500)
	{
		while(Npst<n)
		{
			memset(book,0,sizeof(book));
			int p=1;
			for(int i=Npst+1;i<=n;i++)
			{
				int it=p;
				while(it&&s[it]!=a[i])it--;
				if(it!=0)p=it;
				else s[++p]=a[i];
				
			}
			for(int i=1;i<=p;i++)book[s[i]]=1;
			for(int i=1;i<=m;i++)ans[i]+=book[i];
			Npst++;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	else 
	{
		while(Npst<n)
		{
			memset(book,0,sizeof(book));
			int p=1;
			for(int i=Npst+1;i<=n;i++)
			{
				if(s[p-1]==a[i])p--;
				else s[++p]=a[i];
				
			}
			for(int i=1;i<=p;i++)book[s[i]]=1;
			for(int i=1;i<=m;i++)ans[i]+=book[i];
			Npst++;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	return 0;
}
/*

4 3
1 2 1 3


10 3
3 1 2 1 3 2 3 1 2 1
*/

