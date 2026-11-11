#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5,NN=2e3+5;
ll c,t,a[N],L[N],R[N],n,m;
bool vis[NN][NN];
struct node{
	int l,r;
}ans[N];
int lower(int lw,ll x)
{
	int l=lw,r=n,ans=lw;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<=x)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
int upper(int lw,ll x)
{
	int l=1,r=lw,ans=lw;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>=x)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		ll cnt=0,nm=0;
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			L[i]=upper(i,a[i]-m);
			R[i]=lower(i,a[i]+m);
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+3;j<=n;j++)
			{
				if(min(R[i],j+1)-max(L[j],i-1)==1) 
				{
//					cout<<i<<" "<<j<<"\n";
					vis[i][j]=1;
					ans[++cnt].l=i;
					ans[cnt].r=j;
				}
			}
		}
//		cout<<"\n";
		for(int i=1;i<=cnt;i++)
		{
			for(ll l=ans[cnt].l;l>=1;l--)
			{
				if(a[l+1]-a[l]>m) break;
				for(ll r=ans[cnt].r;r<=n;r++)
				{
					if(a[r]-a[r-1]>m) break;
					if((min(R[l],r+1)-max(L[r],l-1)+1<=0)&&!vis[l][r])
					{
//						cout<<l<<" "<<r<<"\n";
						vis[l][r]=1;
						nm++;
					}
				}
			}
		}
		cout<<nm+cnt<<"\n";
	}
	return 0;
}

