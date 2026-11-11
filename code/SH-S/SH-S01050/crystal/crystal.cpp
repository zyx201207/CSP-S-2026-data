#include<bits/stdc++.h>
using namespace std;
long long n,m;
#define MAXN 500005
long long a[MAXN],diff[MAXN],cnt[MAXN],ans[MAXN],s[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
	{
		diff[i]=a[i+1]-a[i];
	}
	cnt[1]=1;
	for(int i=2;i<=n;i++)
	{
		s[i]=0;
		for(int j=i-1;j>=1;j--)
		{
			s[j]=s[j+1]+diff[j];
			ans[i]+=s[j];
			if(ans[i]>m) break;
			cnt[i]=i-j+1;
		}
	}
	long long ann=0;
	for(int i=1;i<=n;i++)
	{
		ann=max(ann,cnt[i]);
	}
	cout<<ann;
	return 0;
 } 
