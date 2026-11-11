#include<bits/stdc++.h>
using namespace std;
long long a[200005],re[200005],reb[200005],sre[200005];
char c[200005],rc[200005],rcb[200005];
long long sum[200005],v[30][200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	long long cnt=sum[n];
	long long m=cnt/2;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>=m)
		{
			re[i]=m-sum[i-1];
			rc[i]=c[i];
			k=i;
			break;
		}
		else
		{
			re[i]=a[i];
			rc[i]=c[i];
		}
	}
	for(int i=1;i<=k/2;i++)
	{
		swap(re[i],re[k-i+1]);
		swap(rc[i],rc[k-i+1]);
	}
	for(int i=1;i<=k;i++)
	{
		sre[i]=sre[i-1]+re[i];
		for(int j=1;j<=26;j++)
		{
			v[j][i]=v[j][i-1];
		}
		v[int(rc[i]-'a'+1)][i]+=re[i];
	}
	if(cnt%2==1)
	{
		m++;
	}
	int t=0;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>m)
		{
			if(sum[i-1]<=m)
			{
				reb[++t]=sum[i]-m;
				rcb[t]=c[i];
			}
			else
			{
				reb[++t]=a[i];
				rcb[t]=c[i];
			}
		}
	}
	long long q=0,lq=0,ans=0;
	for(int i=1;i<=t;i++)
	{
		q+=reb[i];
		int l=lower_bound(sre+1,sre+k+1,lq)-sre;
		int r=lower_bound(sre+1,sre+k+1,q)-sre;
		if(l<r)
			ans+=reb[i]-(v[int(rcb[i]-'a'+1)][r]-v[int(rcb[i]-'a'+1)][l]);
		if(rc[l]!=rcb[i]&&l!=0)
		{
			ans+=sre[l]-lq;
		}
		if(rc[r]!=rcb[i]&&r!=k+1)
		{
			ans-=sre[r]-q;
		}
		lq=q;
	}
	cout<<ans;
	return 0;
} 
