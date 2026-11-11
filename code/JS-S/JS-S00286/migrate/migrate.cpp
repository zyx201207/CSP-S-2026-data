#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int a[2000005],l[2000005],r[2000005],L[2000005],R[2000005],d[2000005],d2[2000005],d3[2000005];
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989*/
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--)
	{
		int n=read(),dis=read();
		a[0]=-3000000000000000000;
		a[n+1]=3000000000000000000;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		{
			r[i]=upper_bound(a,a+n+2,a[i]+dis)-a-1;
			l[i]=lower_bound(a,a+n+2,a[i]-dis)-a;
			//cout<<l[i]<<' '<<r[i]<<'\n';
		}
		int ans=0,Rr=0;
		for(int i=1;i<=n;i++)
		{
			l[i]=n-l[i]+1,r[i]=n-r[i]+1;
			swap(l[i],r[i]);
		}
		reverse(l+1,l+n+1);reverse(r+1,r+n+1);
		for(int i=1;i<=n;i++)
		{
			R[i]=R[l[i]];
			if(l[i]!=i)R[i]+=d[i-1]-d[l[i]];
			if(r[i]-i<2)
			{
				R[i]++;
				d[i]=d[i-1]+R[i];
				continue;
			}
			if(i<=Rr&&r[r[i]-1]-r[r[i]-2]<=0)
			{
				d[i]=d[i-1]+R[i];
				continue;
			}
			if(i>Rr)
			{
			//cout<<i<<' '<<L[i]<<"!\n";
				d[i]=d[i-1]+R[i];
			}
			R[i]++;
			if(r[r[i]-1]-r[r[i]-2]>0)
			{
				Rr=r[r[i]];
				continue;
			}
		}
		Rr=0;
		for(int i=1;i<=n;i++)
		{
			l[i]=n-l[i]+1,r[i]=n-r[i]+1;
			swap(l[i],r[i]);
		}
		reverse(l+1,l+n+1);reverse(r+1,r+n+1);reverse(R+1,R+n+1);
		for(int i=1;i<=n;i++)d3[i]=d3[i-1]+R[i];
		for(int i=1;i<=n;i++)
		{
			L[i]=L[l[i]];
			if(l[i]!=i)L[i]+=d2[i-1]-d2[l[i]];
			if(r[i]-i<2)
			{
				L[i]++;
				d2[i]=d2[i-1]+L[i];
				continue;
			}
			if(i<=Rr&&r[r[i]-1]-r[r[i]-2]<=0)
			{
				d2[i]=d2[i-1]+L[i];
				continue;
			}
			if(i>Rr)
			{
			//cout<<i<<' '<<L[i]<<"!\n";
				d2[i]=d2[i-1]+L[i];
			}
			L[i]++;
			if(r[r[i]-1]-r[r[i]-2]>0)
			{
				ans=ans+L[i]*(d3[r[r[i]-1]]-d3[r[r[i]-2]]);
				Rr=r[r[i]];
				continue;
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)a[i]=l[i]=r[i]=L[i]=R[i]=d[i]=d2[i]=d3[i]=0;
	}
	return 0;
}
//ta chang zhe ta xiang yu gu zhi
//yi bu yi ju shi xiang si
//tai xia ren jin bang zheng ti ming
//bu cen ren tai shang jiu xiang shi
//ta chang zhe dong fang hua zhu shi
//zhong ren he jia ren pei cai zi
//wei ting yi ju yi tan xi li you qing chi
