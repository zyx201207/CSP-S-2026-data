#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans,x[2000005];
int nxt[2000005],pre[2000005];
int cnt[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,l,r,mid,res;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>x[i];
		l=1;
		for(i=1;i<=n;i++)
		{
			while(l<=i&&x[i]-x[l]>d)l++;
			pre[i]=l;
		}
		l=n;
		for(i=n;i>=1;i--)
		{
			while(l>=i&&x[l]-x[i]>d)l--;
			nxt[i]=l;
		}
//		for(i=1;i<nxt[1];i++)pre[i]=0;
//		for(i=pre[n]+1;i<=n;i++)nxt[i]=n+1;
		cnt[0]=0;
		ans=0;
		for(i=1;i<=n;i++)cnt[i]=0;
		x[n+1]=x[0]=0;
//		cout<<(x[4]-x[3]<=d)<<"\n";
		for(i=1;i<=n;i++)
		{
			cnt[i]++;
			if(i==1||x[nxt[i]]-x[i-1]>d)cnt[nxt[i]]+=cnt[i];
			j=cnt[i]-1;
			if(i<n&&x[i+1]-x[pre[i]]<=d)continue;
//			{
//				cout<<x[i-1]-x[pre[i]-1]<<"?\n";
				if(pre[i]>1&&x[i-1]-x[pre[i]-1]<=d)j=1;
//				else j=0;
//			}
			if(i<=2)continue;
			if(pre[i]==i)continue;
			
			l=max(i+1,nxt[i-2]+1);
			r=min(n,nxt[i-1]);
			if(l<=r)
			{
//				for(mid=i;mid!=1;mid=pre[mid])cout<<mid<<" ";cout<<"\n";
//				cout<<i<<" "<<l<<" "<<r<<" "<<j<<"!\n";
				ans+=(r-l+1)*j;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13

0 1
6 3
0 1 2 3 4 7

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/