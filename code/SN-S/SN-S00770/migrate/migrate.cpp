#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10;
int n;
ll d;
ll x[N];
int L[N],R[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,T;
	scanf("%d%d",&id,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		int j=0;
		for(int i=1;i<=n;i++){
			if(j<i)j=i;
			while(j<=n&&x[j]-x[i]<=d)j++;
			R[i]=j-1;
		}
		j=1;
		for(int i=1;i<=n;i++){
			while(j<i&&x[i]-x[j]>d)
			{
				j++;
			}
			L[i]=j;
		}
		ll ans=0;
		int cnt[N];
		int pre[N];
		for(int u=1;u<=n;u++){
			for(int i=1;i<=n;i++)cnt[i]=0;
			cnt[u]=1;
			int a=u,b=u;
			while(b<n){
				int na=b+1;
				int nb=R[b];
				if(na>nb)break;
				pre[a-1]=0;
				
				for(int i=a;i<=b;i++)
					pre[i]=pre[i-1]+cnt[i];
				
				for(int v=na;v<=nb;v++){
					int left=max(a,L[v]);
					cnt[v]=pre[b]-pre[left-1];
				}
				a=na,b=nb;
			}
			for(int v=u+1;v<=n;v++){
				if(cnt[v]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
