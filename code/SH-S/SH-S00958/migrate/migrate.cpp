#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,t;
int n,dis;
int a[5005];
int mini[5005];
int d[5005];
int cnt[5005];

/*int gai(int ind,int num,int numcnt)
{
	if(num>mini[ind])
	{
		return;
	}
	else if(num<mini[ind])
	{
		mini[ind]=num;
		cnt[ind]=1;
		return;
	}
	else
	{
		cnt[ind]+=numcnt;
	}
	return;
}*/


 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t-->0)
	{
		cin>>n>>dis;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			//从i开始 
			for(int j=i;j<=n;j++)
			{
				mini[j]=1e17;
				cnt[j]=0;
				d[j]=0;
			}
			mini[i]=0;
			cnt[i-1]=0;
			d[i]=1;
			d[i+1]=-1;
			int rmax=i;
			int lmin=i;
			for(int j=i;j<=n;j++)
			{
				cnt[j]=cnt[j-1]+d[j];
				while(mini[lmin]<mini[j]+1 and lmin<=n)
				{
					lmin++;
				}
				//从第一个mini是mini[i]+1而不是mini[i]的，到rmax
				while(a[rmax+1]-a[j]<=dis and rmax+1<=n)
				{
					rmax++;
					mini[rmax]=mini[j]+1;
				}
				if(lmin<=rmax)
				{
					d[lmin]+=cnt[j];
					d[rmax+1]-=cnt[j]; 
				}
			}
			for(int j=i;j<=n;j++)
			{
				//cout<<"!!!"<<i<<" "<<j<<" "<<cnt[j]<<endl;
				if(cnt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

