//bqq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[2000010];
int n,m;
int nxt[2000010],pre[2000010];
int f[5010][5010];
int nn[2000010],b[2000010];
//map<pair<int,int>,int>mp;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int tid,t;
	cin>>tid>>t;
	while(t--)
	{
//		mp.clear();
		cin>>n>>m;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=3)
		{
			puts("0");
			continue;
		}
		if(tid==0)
		{
			int d=a[2]-a[1];
			int x=m/d;
			cout<<(x<=1||x>=n-1?0:n-2*x+1)<<endl;
			continue;
		}
		nxt[n]=1e18;
		for(int i=1;i<=n;i++) b[i]=pre[i]=0;
		int cnt=0;
		for(int i=1;i<n;i++)
		{
			b[i]=cnt+1;
			if(a[i+1]-a[i]<=m) nxt[i]=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
			else nxt[i]=0,nn[++cnt]=i;
//			mp[{a[i],a[nxt[i]]}]=mp[{a[nxt[i]],a[i]}]=1;
		}
		b[n]=cnt+1,nn[++cnt]=n;
//		for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
//		cout<<endl;
		for(int i=1;i<n;i++) for(int j=i+1;j<=nxt[i];j++) if(!pre[j]&&b[i]==b[j]) pre[j]=i;
//		for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
//		cout<<endl;
		memset(f,0,sizeof(f));
		for(int o=1;o<=cnt;o++)
		{
			for(int i=nn[o-1]+1;i<=nn[o];i++)
			{
				for(int j=i+1;j<=nn[o];j++)
				{
					vector<int>v1,v2;
					for(int k=i;;k=nxt[k])
					{
						if(k>=j)
						{
							v1.push_back(j);
							break;
						}
						v1.push_back(k);
					}
					for(int k=j;;k=pre[k])
					{
						if(k<=i)
						{
							v2.push_back(i);
							break;
						}
						v2.push_back(k);
					}
	//				cout<<i<<" "<<j<<endl;
	//				for(int x:v1) cout<<x<<" ";
	//				cout<<endl;
	//				for(int x:v2) cout<<x<<" ";
	//				cout<<endl<<endl;
					if(v1.size()==v2.size())
					{
						reverse(v2.begin(),v2.end());
						int c=0;
						for(int k=0;k<v1.size()&&c<=1;k++) c+=(abs(v1[k]-v2[k])==1);
						if(c==1)
						{
							f[i][j]=1;
//							cout<<i<<" "<<j<<endl;
//							for(int x:v1) cout<<x<<" ";
//							cout<<endl;
//							for(int x:v2) cout<<x<<" ";
//							cout<<endl<<endl;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans+=f[i][j];
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
6 5
1 3 4 8 9 13
*/
