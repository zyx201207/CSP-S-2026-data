#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
const int INF=0x3f3f3f3f;
ll c,t,n,d,ans;
ll a[N],minn[N],cnt[N];
void dfs(int x,int sum){
	if(sum>minn[x]) return;
	if(sum==minn[x]) cnt[x]++;
	else minn[x]=sum,cnt[x]=1;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			dfs(i,sum+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		ans=0;
		for(int i=1;i<=n;i++){
			memset(minn,INF,sizeof(minn));
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}