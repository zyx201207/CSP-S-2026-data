#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5,maxv=30;
int n,m,a[maxn+5],maxp=0;
int f[maxv+5][maxn+5],sum[maxv+5][maxn+5],maxs[maxv+5];
int nn,na[maxn+5],nf[maxv+5][maxn+5],nsum[maxv+5][maxn+5],nmaxs[maxv+5];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int p=0,tmp=a[i];
		while(tmp)
		{
			if(tmp&1) f[p][i]=1,sum[p][i]=maxs[p]+1;
			maxs[p]=max(maxs[p],sum[p][i]);
			p++;
			tmp>>=1;
		}
		maxp=max(maxp,p-1);
	}
	bool flag=1;
	for(int p=maxp;p>=0;p--)
	{
		if(maxs[p]<m) continue;
		else if(maxs[p]==m)
		{
			int ans=(1<<(maxp+1))-1;
			for(int i=1;i<=n;i++) if(f[p][i]==1) ans&=a[i];
			cout<<ans;
			return 0;
		}
		else if(maxs[p]>m)
		{
			flag=0;
			nn=0;
			memset(na,0,sizeof(na));
			memset(nf,0,sizeof(nf));
			memset(nsum,0,sizeof(nsum));
			memset(nmaxs,0,sizeof(nmaxs));
			for(int i=1;i<=n;i++)
			{
				if(f[p][i]==1)
				{
					nn++;
					na[nn]=a[i];
					int q=0,tmp=a[i];
					while(tmp)
					{
						if(tmp&1) nf[q][nn]=1,nsum[q][nn]=nmaxs[q]+1;
						nmaxs[q]=max(nmaxs[q],nsum[q][nn]);
						q++;
						tmp>>=1;
					}
				}
			}
			n=nn;
			for(int i=1;i<=nn;i++)
			{
				a[i]=na[i];
				for(int q=p;q>=0;q--)
				{
					f[q][i]=nf[q][i];
					sum[q][i]=nsum[q][i];
				}
			}
			for(int q=p;q>=0;q--) maxs[q]=nmaxs[q];
		}
	}
	if(!flag)
	{
		int ans=(1<<(maxp+1))-1;
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
