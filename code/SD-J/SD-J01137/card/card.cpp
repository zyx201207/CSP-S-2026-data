#include <bits/stdc++.h>
using namespace std;
int ans[300005],a[500005],bd[500005],added[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnum=0,cnum2;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) bd[j]=0;
		cnum=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=cnum;k++){
				if(bd[k]==a[j]){
					cnum2=cnum;
					for(int l=k;l<=cnum;l++)
					{
						bd[l]=0;
						cnum2--;
					}
					cnum=cnum2;
					break;
				}
			}
			bd[cnum+1]=a[j];
			cnum++;
		}
		for(int j=1;j<=cnum;j++)
		{
			if(added[bd[j]]==0)
			{
				ans[bd[j]]++;
				added[bd[j]]=1;
			}
			for(int k=1;k<=m;k++) added[k]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
