#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,x[2000005],f[2000005],ans,c,t,fr[2000005],r[2000005],l[2000005],fcnt[2000005],cnt1[2000005],cnt2[2000005];
const int inf=0x3f3f3f3f3f3f3f3f;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--)
	{
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if (n==1)
		{
			cout<<0<<'\n';
			continue;
		}
		if (c==11||c==12)
		{
			if ((x[2]-x[1])*2>d||d>=x[n]-x[1])
			{
				cout<<0<<'\n';
			}
			else
			{
				
			cout<<n-1-(2*(d/(x[2]-x[1]))-1)+1<<'\n';
			}
			continue;
		}
		if (c==13||c==14)
		{
			x[n+1]=inf;
			for (int i=1;i<=n;i++)
			{
				cnt1[i]=cnt2[i]=0;
			}
			for (int i=1;i<=n;i++)
			{
				if (i!=1)cnt1[lower_bound(x+1,x+n+2,x[i]-d)-x]++;
				if (i!=n)cnt2[upper_bound(x+1,x+n+2,x[i]+d)-x-1]++;
			}
			for (int i=1;i<n;i++)
			{
				ans+=cnt1[i]*cnt2[i+1];
			}
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		if (c>=15&&c<=18)
		{
			x[n+1]=inf;
			for (int i=1;i<n;i++)
			{
				r[i]=upper_bound(x+1,x+n+2,x[i]+d)-x-1;
//				r[i]=min(r[i])
//				cerr<<r[i]<<" ";
			}
			for (int i=2;i<=n;i++)
			{
				l[i]=lower_bound(x+1,x+n+2,x[i]-d)-x;
			}
			for (int i=1;i<=n;i++)
			{
				int cur=i,lstcur=0;
				fcnt[i]=1;
				while (cur<n&&r[cur]!=cur)
				{
//					cerr<<cur<<' '<<ans<<' '<<fcnt[cur]<<' '<<fcnt[cur-1]<<"  ";
					if (lstcur==cur-1||lstcur==0)
					{
						if (fcnt[cur]==3||fcnt[cur]==0)
						{
							break;
						}
						if (fcnt[cur]==2)
						{
							ans+=r[cur]-cur;
						}
						if (r[cur]==cur+1)
						{
							fcnt[r[cur]]=fcnt[cur];
							fcnt[r[cur]-1]=3;
//							if (fcnt[cur]==2)
//							{
//								ans++;
//							}
						}
						else
						{
							fcnt[r[cur]]=fcnt[r[cur]-1]=fcnt[cur];
						}
						
					}
					else if (lstcur==cur-2)
					{
						if (fcnt[cur]==2)
						{
							ans+=r[cur]-r[cur-1];
							fcnt[r[cur]]=fcnt[r[cur]-1]=2;
						}
						else if (fcnt[cur]==1&&fcnt[cur-1]==1)
						{
							ans+=r[cur-1]-cur;
							fcnt[r[cur]]=2;
							fcnt[r[cur]-1]=2;
						}
						else
						{
							fcnt[r[cur]]=fcnt[r[cur]-1]=3;
							
						}
					}
					else
					{
//						cerr<<":";
						if (fcnt[cur]==2)
						{
							ans+=r[cur]-r[cur-1];
						
							fcnt[r[cur]]=fcnt[r[cur]-1]=2;
							if (r[cur-1]==r[cur]-1)
							{
								fcnt[r[cur]-1]=3;
							}
							if (r[cur-1]==r[cur])
							{
								fcnt[r[cur]]=3;
							}
							
						}
						else if (fcnt[cur]==1&&fcnt[cur-1]==1)
						{
							ans+=r[cur-1]-r[cur-2];
							fcnt[r[cur]]=2;
							fcnt[r[cur]-1]=2;
						}
						else
						{
							fcnt[r[cur]]=fcnt[r[cur]-1]=3;
						}
					}
					lstcur=cur;
					cur=r[cur];
				}
				cerr<<ans<<'\n';
			}
			cout<<ans<<'\n';
//			cerr<<":::::\n";
			continue;
		}
//		cerr<<"--------";
		for (int i=1;i<=n;i++)
		{
//			cerr<<i<<":";
			for (int j=1;j<=n;j++)
			{
				f[j]=inf;
				fcnt[j]=0;
				fr[i]=0;
			}
			f[i]=0;
			fcnt[i]=1;
			fr[0]=i;
			int k=i;
			for (int j=i+1;j<=n;j++)
			{
//				cerr<<i<<' '<<j<<'\n'; 
				while (x[j]-x[k]>d)
				{
					k++;
				}
				if (j==k)
				{
					break;
				}
//				cerr<<k<<'_'<<f[k]<<'\n';
				f[j]=f[k]+1;
				fr[f[j]]=j;
				if (fr[f[k]]-k+1>=3)
				{
					fcnt[j]=3;
				}
				else if (fr[f[k]]-k+1==2)
				{
					if (fcnt[k]+fcnt[k+1]>2)
					{
						fcnt[j]=3;
						
					}
					else
					{
						fcnt[j]=2;
						ans++;
//						cerr<<f[j]<<' ';
					}
				}
				else
				{
					fcnt[j]=fcnt[k];
					if (fcnt[k]==2)
					{
						ans++;
//						cerr<<f[j]<<' ';
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	/*
	15 1
	6 9
	1 3 5 7 9 11
	*/
	return 0;
}

