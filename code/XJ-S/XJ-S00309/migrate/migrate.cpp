#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int ls[2000005],rs[2000005],l[2000005],r[2000005],lsi[2000005],rsi[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long i,j,k,n,m,q,ans,sum,nu;
	cin>>n>>q;
	while(q--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		memset(l,0,sizeof l);
		memset(ls,0,sizeof ls);
		memset(lsi,0,sizeof lsi);
		memset(r,0,sizeof r);
		memset(rs,0,sizeof rs);
		memset(rsi,0,sizeof rsi);
		for(i=1;i<n;i++)
		{
			int le=i+1,ri=n,mid;
			while(le<ri)
			{
				mid=(le+ri)/2;
				if(a[mid]>m+a[i]) ri=mid;
				else le=mid+1;
			}
			if(le-1!=i&&a[le]>a[i]+m)
			{
				if(l[le-1]==0) l[le-1]=i;
				ls[le-1]++;
			}
		}
		for(i=n;i>1;i--)
		{
			int le=1,ri=i-1,mid;
			while(le<ri)
			{
				mid=(le+ri)/2+1;
				if(a[mid]<a[i]-m) le=mid;
				else ri=mid-1;
			}
			if(le+1!=i&&a[le]<a[i]-m)
			{
				if(r[le+1]==0) r[le+1]=i;
				rs[le+1]++;
			}
		}
		for(i=1;i<=n;i++)
		{
			lsi[i]+=ls[i];
			if(l[r[i]]==i) lsi[r[i]]+=lsi[i];
		}
		for(i=n;i>=1;i--)
		{
			rsi[i]+=rs[i];
			if(r[l[i]]==i)
			{
				rsi[l[i]]+=rsi[i];
			}
		}
		ans=0;
		int ll=0,rr=0,suml,sumr;
		for(i=1;i<n;i++)
		{
			if(i-l[i]<2||l[i]==0||r[i-1]==0||r[i-1]-i+1<2) continue;
			ans+=lsi[i]*rsi[i-1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
