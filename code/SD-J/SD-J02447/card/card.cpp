#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int n,m,a[500010],f[300030],s[500010],ans[300010],top;
signed main()
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
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]])	
			{
				top=0;
				memset(f,0,sizeof f);
			}
			f[a[j]]=1;
			s[++top]=a[j];
		}
		for(int i=1;i<=top;i++)
		{
//			cout<<s[i]<<' ';
			ans[s[i]]++;
		}
//		cout<<'\n';
		top=0;
		memset(f,0,sizeof f);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}

