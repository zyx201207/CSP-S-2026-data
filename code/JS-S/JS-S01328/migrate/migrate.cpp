#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int c,T;
ll n,d;
ll a[2000050];
ll arr[2000050];
//expected: 32pts
//hmm...T3 looks like not so easy...
//better do sth to get rid of long long
//wait i am thinking of fenzhi
//fenzhi[i][j]=double-path-pair inside i~j
//how to combine subquestions?
//a+b=a.inside+b.inside+a_to_b
//i'm a bit of dizzy...
//how can i know if (u,v) is double-pair?
//it's too hard.What if dp?
//dp is bad.I gonna need to find some guilv
int can_go_l[2000050],can_go_r[2000050];
ll ans=0;
int dp[550][550][550];//from i to j & len=k path cnt
int minlen[550][550];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			arr[i]=a[i]-a[1];
		}
		can_go_l[1]=1;
		for(int i=1;i<=n;i++)
		{
			if(arr[i]>d)
			{
				break;
			}
			can_go_r[1]=i;
		}
		for(int i=2;i<=n;i++)
		{
			can_go_l[i]=can_go_l[i-1];
			can_go_r[i]=can_go_r[i-1];
			while(arr[i]-arr[can_go_l[i]]>d)
			{
				can_go_l[i]++;
			}
			while(can_go_r[i]<n && arr[can_go_r[i]]-arr[i]<=d)
			{
				can_go_r[i]++;
			}
			if(arr[can_go_r[i]]-arr[i]>d)
			{
				can_go_r[i]--;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<can_go_l[i]<<"<->"<<can_go_r[i]<<endl;
//		}
		if(c==11 || c==12)
		{
			if(arr[2]*2>d)
			{
				cout<<0<<endl;
			}
			else
			{
				int tmp=d/arr[2];//can jump over ? islands
				cout<<max(0ll,n-(2*tmp-1))<<endl;
			}
			continue;
		}
		if(c==13 || c==14)
		{
			;
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					dp[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][i][0]=1;
		}
		for(int j=0;j<=n;j++)
		{
			for(int j2=j+1;j2<=can_go_r[j];j2++)
			{
				for(int i=1;i<=j;i++)
				{
					for(int k=1;k<=n;k++)
					{
						dp[i][j2][k]+=dp[i][j][k-1];
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int found=0;
				for(int k=1;k<=n;k++)
				{
					if(dp[i][j][k]==2)
					{
						found=1;
//						cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"]=2"<<endl;
						break;
					}
					if(dp[i][j][k]!=0)
					{
						break;
					}
				}
				ans+=found;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
