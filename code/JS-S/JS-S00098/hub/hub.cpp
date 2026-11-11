#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,x2[10009],x3[1000009],x4[1000009];
vector<int>x1[10009];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(x4,0,sizeof(x4));
		memset(x3,0,sizeof(x3));
		int ff=0,rr=0;
		int n,k,r=0,ans=0,minn=1e18;
		scanf("%lld%lld",&n,&k);
		memset(x2,0,sizeof(x2));
		for(int i=1;i<n;i++){
			long long u,v;
			scanf("%lld%lld",&u,&v);
			x1[u].push_back(v);
			x1[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=0;
				x2[i]=x2[j]=1;
				x3[++rr]=i,x3[++rr]=j;
				while(1){
					for(int kk=1;kk<=n;kk++)ans+=x2[kk];
					if(ans>=k){
						minn=min(minn,r);
						continue;
					}
					++ff;
					for(auto y:x1[ff]){
						if(x2[y]!=1)x2[y]=1,x4[y]=x4[ff]+1,r=x4[ff];
					}
				}

			}
		}
		printf("%lld\n",minn);
	}
	return 0;
}
