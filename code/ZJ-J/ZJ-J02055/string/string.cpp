#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,ans,s,ii,cnt[400005],cs,sum1,s1;
char c[200005];
struct E{
	long long l,r;
	char cc;
}m[400005];
struct E1{
	long long l,r;
	char cc;
}cntt[400005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum1=sum;
	sum=(sum+1)/2;
	for(long long i=1;i<=n;i++)
	{
		ii+=1;
		m[++s].l=ii;
		ii+=a[i]-1;
		m[s].cc=c[i];
		if(m[s].l<=sum&&ii>sum)
		{
			m[s].r=(sum1-1)/2;
			cnt[++cs]=m[s].r;
			if(m[s].r!=sum1-m[s].l+1)cnt[++cs]=sum1-m[s].l+1;
			m[++s].l=sum+1;
			m[s].cc=c[i];
		}
		m[s].r=ii;
		cnt[++cs]=m[s].r;
		if(m[s].r!=sum1-m[s].l+1)cnt[++cs]=sum1-m[s].l+1;
	}
	sort(cnt+1,cnt+cs+1);
	for(long long i=1;i<=cs;i++)
	{
		if(cnt[i]!=cnt[i-1])
		{
			cntt[++s1].r=cnt[i];
			cntt[s1].l=cntt[s1-1].r+1;
		}
	}
	long long x=1;
	for(long long i=1;i<=s;i++)
	{
		for(;cntt[x].r<=m[i].r;x++)
		{
			cntt[x].cc=m[i].cc;
			if(cntt[x].l==sum)cntt[x].l=m[i].l;
		}
	}
	for(long long i=1;i<=s1/2;i++)if(cntt[i].cc!=cntt[s1-i+1].cc)ans+=(cntt[i].r-cntt[i].l+1);
	cout<<ans;
	return 0;
}
