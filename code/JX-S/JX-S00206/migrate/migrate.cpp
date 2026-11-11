#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define dep(a,b,c) for(int a=b;a>=c;--a)
const int N = 5007; const int inf = 1e9+7;
int c,T,n,d,x[N],yy[N],f[N],b[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		int l,las=0,ans=0; memset(b,0,sizeof(b));
		cin>>n>>d; rep(i,1,n) cin>>x[i];
		rep(i,1,n)
		{
			while(x[las+1]<=x[i]+d&&las<n) las++;
			yy[i]=las;
		}
		dep(i,n,1) b[i]=b[yy[i]]+1;
		las=0;
		rep(u,1,n)
		{
			memset(f,0,sizeof(f));
			l=las=u; f[u]=1;
			rep(k,1,b[u])
			{
				while(yy[l]<las+1&&l<las) l++;
				dep(i,las,max(l,las-3))
				    dep(j,yy[i],las+1)
				    {
						if(f[j]>2) break;
						f[j]+=f[i];
					}
				l=las+1; las=yy[las];
			}
			rep(i,u,n) if(f[i]==2) ans++;
			/* ts
			if(n<=30){
			cout<<u<<" : "<<ans<<"  f[i]:   ";
			rep(i,u,n) cout<<f[i]<<" ";
			cout<<endl;}
			/**/
		}
		cout<<ans<<endl;
	}
	return 0;
}
