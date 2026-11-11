#include <bits/stdc++.h>
using namespace std;
unsigned long long ans=0;
long long a[500005],n,m,minn=1e18,ch[500005],cnt=0,maxn=-1,ans1;
bool cmp(int b,int c)
{
	return b<c;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ch[0]=0;
	for(int i=1;i<=n;i++)
	{
			ch[i]=abs(a[i+1]-a[i]);  //1
			if(i!=1)
			minn=min(minn,abs(a[i]-a[i-1]));
	}
	if(minn>m&&n!=1)
	cout<<1; 
	else if(n==1)
	cout<<1;
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans=0;
			cnt=0;
			ans1=0;
			for(int j=i-1;j>=1;j--)
			{
				ans1+=ch[j];
			    ans+=ans1;
				if(ans<=m)
					cnt++;
				else 
				break;
			}
			maxn=max(maxn,cnt+1);
		}
		cout<<maxn; 
	}
	return 0;
}

 
