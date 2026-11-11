#include<bits/stdc++.h>
using namespace std;
int c,dt,sta,stmax,askk;
int a[510][10010];
int dtarr[510];
int kintoz[1010];
int qu[500010][2];
int ans[500010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>dt>>sta>>stmax>>askk;
	for(int i=1;i<=sta;i++)cin>>kintoz[i];
	for(int i=1;i<=dt;i++)
	{
		cin>>dtarr[i];
		for(int j=1;j<=dtarr[i];j++)
		{
			int w;
			cin>>w;
			cin>>a[i][w];
		}
	}
	for(int i=1;i<=askk;i++)
	{
		cin>>qu[i][1]>>qu[i][2];
		ans[i]=1000000;
	}
	for(int i=1;i<=askk;i++)
	{
		for(int j=1;j<=dt;j++)
		{
			if(a[j][qu[i][1]]!=0)
			{
				for(int k=j;k<=dt;k++)
				{
					if(a[k][qu[i][2]]!=0)
					{
						if(k==j)
						{
							ans[i]=min(ans[i],a[j][qu[i][1]]+a[j][qu[i][2]]);
						}
						else
						{
							for(int l=1;l<=sta;l++)
							{
								if(a[k][l]!=0 && a[j][l]!=0)
								{
									ans[i]=min(ans[i],a[j][qu[i][1]]+a[k][qu[i][2]]+a[j][l]+a[k][l]);
								}
							}
						}
					}
				}
			}
		}
		ans[i]+=(kintoz[qu[i][1]]+kintoz[qu[i][2]]);
	}
	for(int i=1;i<=askk;i++)
	{
		cout<<ans[i]<<endl;
	}
}
