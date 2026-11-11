#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int t,n,c,f[N],ans,l,r;
long long d,a[N],b[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++) f[j]=1e9;
			l=r=i;
			f[i]=0;
			b[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				r++;
				while(l<r&&a[r]-a[l]>d) l++;
				for(int k=l;k<=r;k++)
					f[j]=min(f[k]+1,f[j]);
				if(f[i]==1e9) break;
				long long cnt=0;
				for(int k=l;k<=r;k++) if(f[k]==f[j]-1) cnt+=b[k];
				b[j]=cnt;
				if(cnt==2) ans++; 
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}