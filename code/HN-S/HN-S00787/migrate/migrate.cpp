#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000007],f[2000007],cnt[2000007],ct[2000007],q[2000007],st=1,ed=0; 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int ans=0;
		for(int k=1;k<=n;k++)
		{
			memset(f,0x3f,sizeof(f));
			memset(cnt,0,sizeof(cnt));
			memset(ct,0,sizeof(ct));
			f[k]=0;
			st=ed=1;
			ct[0]=1;
			q[1]=k;
			for(int i=k+1;i<=n;i++)
			{
				while(st<=ed && x[i]-x[q[st]]>d)
				{
					ct[f[q[st]]]--;
					st++;
				}
				if(st>ed)
				{
					break;
				}
//				cout<<i<<" "<<q[st]<<" "<<f[q[st]]<<" "<<ct[f[q[st]]]<<"-=\n";
				f[i]=f[q[st]]+1;
				cnt[i]=ct[f[q[st]]];
				while(st<=ed && f[q[ed]]>f[i])
				{
					ct[f[q[ed]]]--;
					ed--;
				}
				ed++;
				q[ed]=i;
				ct[f[i]]++;
			}
			for(int i=k;i<=n;i++)
			{
				cout<<f[i]<<"-"<<cnt[i]<<" ";
				if(cnt[i]==2)
				{
					ans++;
				}
			}
			cout<<"\n\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0 1
10 3
0 3 6 7 8 9 10 11 14 17

7
*/
