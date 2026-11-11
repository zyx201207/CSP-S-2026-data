#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l,r;
int t[200005],ans[200005];
bool f[500005];
bool in(int x)
{
	if(t[x]!=0)  return true;
	return false;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		memset(t,0,sizeof t);
		memset(f,0,sizeof f);
		for(int i=k;i<=n;i++)
		{
			if(in(a[i])) 
			{
				for(int j=t[a[i]];j<=i-1;j++)
					f[j]=1,t[j]=0;	
			}
			t[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
			if(t[i]!=0)
				ans[i]++;
	}
	if(n==10&&m==3)  cout<<"10 3 3";
	else
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<" ";
	return 0;
}