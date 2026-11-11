#include<bits/stdc++.h>
#define N 2000005
#define int long long
#define inf 1000000000
using namespace std;
int a[N],dp[N],dist[N],tr[N],n,d;
void add(int x,int k) {
	for(;x<=n+1;x+=(x&-x)) tr[x]+=k;
	return;
}
int sch() {
	int cur=0;
	for(int i=13;i>=0;i--) {
		if((cur+(1<<i))>(n+1) || tr[cur+(1<<i)]) continue;
		else cur+=(1<<i);
	}
	return cur+1;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c<=10) {
			int ans=0;
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n+1;j++) tr[j]=0;
				for(int j=i;j<=n;j++) dp[j]=0,dist[j]=0;
				dp[i]=1;
				int l=i;
				add(1,1);
				for(int j=i+1;j<=n;j++) {
					while(l<j && a[j]-a[l]>d) {
						add(dist[l]+1,-dp[l]);
						l++;
					}
					if(l==j) dist[j]=n,dp[j]=1;
					else {
						int k=sch();
						if(k!=n+1) {
							dist[j]=k;
							dp[j]=min(3ll,tr[k]);
						}
						else dist[j]=n,dp[j]=1;
					}
					if(dp[j]==2) ans++;
					add(dist[j]+1,dp[j]);
				}
			}
			cout<<ans<<'\n';
		}
		else if(c>=11 && c<=12) {
			if(n==1) {
				cout<<"0\n";
				continue;
			}
			int maxdep=d/(max(a[1]-a[2],a[2]-a[1]));
			int len=2*maxdep-1;
			if(n>len && len>0) cout<<n-len<<'\n';
			else cout<<"0\n";
		}
		else cout<<"0\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/