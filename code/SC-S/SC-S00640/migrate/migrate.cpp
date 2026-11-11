#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;
long long c,t,n,a[N],d,pre[N];
struct Node
{
	long long val,ks;
}f[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c<=10)
		{
			int res=0;
			for(int i=1;i<=n;i++)
			{
				int l=i,r=i;
				f[i]={0,1};
				pre[i]=1;
				for(int j=i+1;j<=n;j++)
				{
					f[j]={0,0};
					while(a[j]-a[l]>d) l++;
					if(l==j) break;
					r=max(r,l);
					while(r+1<j&&f[r+1].val==f[l].val) r++;
					f[j]={f[l].val+1,pre[r]-pre[l-1]};
					f[j].ks=min(f[j].ks,1ll*3);
					if(f[j].ks==2) res++; 
					pre[j]=pre[j-1]+f[j].ks;
				}
				for(int j=1;j<=n;j++) f[j]={0,0},pre[j]=0;
			} 
			cout<<res<<"\n"; 
		}
		if(c==11||c==12)
		{
			long long ds=a[2]-a[1];
			int mx=0;
			for(int i=1;i<n;i++) if(i*ds<=d)
			{
				mx=i;
			}
			long long res=0;
			if(mx>=2) res=n-(mx+mx-1);
			cout<<max(0*1ll,res)<<"\n";
		}
	}
	return 0;
}