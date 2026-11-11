#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
const int inf=1e18;
int c,T,n,d,ans,head,tail,x[N],dp[N],cnt[N],qu[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int u=1;u<n;u++){
			dp[u]=0;
			cnt[u]=1;
			head=1;
			tail=0;
			qu[++tail]=u;
			for(int v=u+1;v<=n;v++){
				dp[v]=inf;
				cnt[v]=0;
				while(head<=tail&&x[qu[head]]<x[v]-d)
					head++;
				if(head<=tail)
					dp[v]=dp[qu[head]]+1;
				else
					break;
				while(head<=tail&&dp[qu[tail]]>dp[v])
					tail--;
				for(int i=head;i<=tail&&cnt[v]<=2;i++)
					if(dp[qu[i]]+1==dp[v])
						cnt[v]+=cnt[qu[i]];
					else
						break;
				if(cnt[v]==2)
					ans++;
				qu[++tail]=v;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
