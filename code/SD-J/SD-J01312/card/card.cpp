#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt[300005],ans[500005],fir[500005];
int f[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		memset(b,0,sizeof(b));
		memset(fir,0,sizeof(fir));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			b[j]=a[j];
			if(cnt[a[j]]>1)
			{
				cnt[a[j]]=1;
				b[fir[a[j]]]*=-1;
			}
			fir[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			bool ccc=true;
			if(b[j]<0)
			{
				f[-b[j]]++;
				if(f[-b[j]]==2)
					f[-b[j]]=0;
			}
			if(b[j]>0&&f[b[j]]>0)
				f[b[j]]=0;
			for(int k=1;k<=m;k++)
			{
				if(f[k])
				{
					ccc=false;
					break;
				}
			}
			if(ccc&&b[j]>0)
				ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
