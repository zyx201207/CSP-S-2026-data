//袁骏逸 SN-J00837 西安市铁一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool flag[500005];
int cnt[500005];
bool die[500005];
int tong[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)flag[j]=0,cnt[j]=0,die[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]])
			{
				
				for(int k=j-1;k>=1;k--)
				{
					if(die[a[k]])continue;
					
					cnt[a[k]]--;
					die[a[k]]=1;
					flag[a[k]]=0;
					if(a[k]==a[j])break;
				}
			}
			cnt[a[j]]++;
			flag[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(cnt[j])
			{
				tong[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
	return 0;
}
