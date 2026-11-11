//5%-50%
#include<bits/stdc++.h>
using namespace std;
int a[100005],ans[100005],re[100005],p,cnt[100005];
bool sur[100005]; 
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		memset(re,-1,sizeof(re)); 
		memset(cnt,0,sizeof(cnt)); 
		memset(sur,0,sizeof(sur)); 
		for(j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			sur[j]=1; 
//			cout<<endl; 
			
//					for(int k=1;k<=m;k++)
//					{
//						cout<<cnt[k]<<" ";
//					}
					
			if(re[a[j]]!=-1&&sur[re[a[j]]])
			{
				for(int k=re[a[j]];k<j;k++)
					if(sur[k])	cnt[a[k]]--,sur[k]=0;
//					cout<<endl;
					
//					for(int k=1;k<=m;k++)
//					{
//						cout<<cnt[k]<<" ";
//					}
			}
			
			re[a[j]]=j;
		}
		for(j=1;j<=m;j++)
		{
//			cout<<cnt[j]<<" ";
			if(cnt[j]>0)
				ans[j]++;
		}
//		cout<<endl; 
	} 
	for(i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
