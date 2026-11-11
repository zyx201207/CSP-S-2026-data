#include<bits/stdc++.h>
using namespace std;
int n,a[100010],k,m,cnt[100010],ans[100010];
bool f[100010],u[100010];
//damn
//shit
//GG
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++)
//	{
//		u[a[i]]=1;
//		cnt[a[i]]++;
//		if(u[a[i]]==1)
//		{
//			for(int k=1;k<=i;k++)
//			{
//				cnt[k]=0;
//			}
//		}
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			u[j]=0;
			cnt[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			ans[a[j]]++;
			if(u[a[j]]==1)
			{
				for(int k=1;k<=j;k++)
				{
					cnt[a[k]]--;
					ans[a[k]]--;
					u[a[k]]=0;
				}
			}			
			u[a[j]]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[a[i]]<<" ";
	}
	return 0;
}
