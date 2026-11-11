#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt1,cnt2,a[500005],b[3005],c[3005],t[300005];
bool vis[5005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1) cout<<n;
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==1) cnt1++;
			else cnt2++;
		if(a[n]==1) cout<<n<<" "<<cnt2;
		else cout<<cnt1<<" "<<n;
	}
	else if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			memset(b,0,sizeof b);
			memset(vis,0,sizeof vis);
			for(int j=i;j<=n;j++)
			{
				if(b[a[j]]&&(!vis[b[a[j]]])) for(int k=b[a[j]];k<j;k++) vis[k]=1; 
				b[a[j]]=j;
			}
			for(int j=i;j<=n;j++) if(!vis[j]) c[a[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	}
	else
	{
		bool flag=1;
		for(int i=1;i<n;i++)
			if(a[i]>a[i+1])
			{
				flag=0;
				break;
			}
		if(flag)
		{
			for(int i=1;i<=n;i++) t[a[i]]=i;
			for(int i=1;i<=m;i++) cout<<t[i]<<" ";
		}
	}
	return 0;
}
