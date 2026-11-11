#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int c,t,n;
long long a[N],d,q[N],l,r,f[N],vis[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			l=r=0;
			memset(f,0x3f,sizeof(f));
			q[r++]=i,f[i]=0;
			memset(vis,0,sizeof(vis));
			for(int j=i+1;j<=n;j++)
			{
				while(l<r&&a[j]-a[q[l]]>d)
				{
					l++;
				}
				if(l==r)break;
				f[j]=f[q[l]]+1;
				int flag=0;
				if(l<r-2&&f[q[l]]==f[q[l+1]]&&f[q[l]]==f[q[l+2]])flag=2;
				else if(l<r-1&&f[q[l]]==f[q[l+1]]&&vis[q[l]]==0&&vis[q[l+1]]==0)flag=1;
				else if(l<r-1&&f[q[l]]==f[q[l+1]]&&(vis[q[l]]!=0||vis[q[l+1]]!=0))flag=2;
				else flag=vis[q[l]];
				vis[j]=flag;
				if(flag==1)
				{
					sum++;
				}
				while(l<r&&f[q[r-1]]>f[j])r--;
				q[r++]=j;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
 } 
