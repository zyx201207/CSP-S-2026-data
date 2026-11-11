#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000009;
ll c,t,n,d,x[N],k[5009][5009],cnt[5009][5009],l,r,ans;
void dfs(ll s,ll p,ll tp){
	if (p==k[tp][s]) cnt[tp][s]++;
	if (p<k[tp][s]) cnt[tp][s]=0;
	k[tp][s]=min(k[tp][s],p);
	for (int i=s+1;i<=n;i++){
		if (x[i]-x[s]>d) break;
		dfs(i,p+1,tp);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if (n<=5000){
		while(t){
			t--;
			ans=0;
			cin>>n>>d;
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++) k[i][j]=1e9+9;
			}
			for (int i=1;i<=n;i++) cin>>x[i];
			for (int i=1;i<=n;i++) dfs(i,0,i);
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					if (cnt[i][j]==1) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
