#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],cnt[500005];
long long now;
int ans;
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1,cmp);
	
	bool flag1=true;
	for(int i=2;i<=n;i++)
	{
		cnt[i-1]=abs(a[i]-a[i-1]);
		if(i>2)
		{
			if(cnt[i-1]!=cnt[i-2])
			{
				flag1=false;
			}
		}
	}
	
	if(flag1)
	{
		int anum=cnt[2];
		for(int i=1;i<=n;i++)
		{
			if(m<0) break;
			m-=anum*i;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		int l=i,r=i+1,avis=1;
		now=0;
		while(r<=n)
		{
			now+=(r-l)*cnt[r-1];
			if(now>m)
			{
				ans=max(ans,avis);
				break;
			}
			avis++;
			r++;
		}
	}
	cout<<ans;
	return 0;
}
