#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int s[300010];
int cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++)
		{
			if(s[a[j]]!=0)
			{
				for(int k=s[a[j]];k<=j-1;k++)
				{
					s[a[k]]=0;
				}
			}
			s[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(s[j]!=0)
			{
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}