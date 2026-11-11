#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+6;
int a[N],b[N],ans=-1e18,tmp,n,m,sum; 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	b[1]=a[1];
	for(int i=2;i<=n;i++) b[i]=b[i-1]+a[i];
	int i=1,j=1,sum=m;
	while(j<=n)
	{
		j++;
		if(j>=n)
		{
			if(m-((b[n]*(n-i+1))-(b[n]-b[i-1]))>0)
			ans=max(ans,n-i+1);
			break;
		}
		sum-=(j-i)*(a[j]-a[j-1]);
		if(sum>0)
		{
			continue;
		}
		else
		{
			tmp=j-i;
			ans=max(ans,tmp);
			while(sum<0)
			{
				i++;
				sum=m-(a[j]*(j-i+1)-(b[j]-b[i-1]));
			}
		}
	}
	if(ans==-1e18) cout<<n;
	else cout<<ans;
	return 0;
}
