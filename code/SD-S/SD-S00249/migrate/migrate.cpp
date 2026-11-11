#include<bits/stdc++.h>
#define int long long
#define ll long long
#define N 2000050
#define M 5050
using namespace std;
ll c,t,a[N],le[N],ri[N],dp[M][M],num[M][M],ans;
deque<ll>q,bei;
void solve(){
	ll n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=1;
	for(int i=1;i<=n;i++){
		while(r<=n){
			if(r<n&&a[r+1]-a[i]<=d)r++;
			else break;
		}
//		while(l<=r){
//			if(a[i]-a[l]>d)l++;
//		}
		le[i]=i,ri[i]=r;
//		cout<<r<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0x3f3f3f3f3f3f,num[i][j]=0;
		}
		dp[i][i]=0,num[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		l=i,r=i;
		ll nnum=0;
		for(int j=i-1;j>=1;j--){
			if(ri[j]==j)break;
			while(!q.empty()){
				ll x=q.back();
				if(dp[x][i]>dp[j+1][i])q.pop_back();
				else break;
			}
			if(!q.empty()){
				ll nowval=dp[q.front()][i];
				while(!q.empty()){
					ll x=q.front();
					if(x>ri[j]){
						q.pop_front();
						if(dp[x][i]==nowval)nnum-=num[x][i];
					}else break;
				}
				if(!q.empty()){
					ll nnowval=dp[q.front()][i];
					if(!q.empty()&&nnowval!=nowval){
						while(!q.empty()){
							ll x=q.front();
							if(dp[x][i]!=nnowval)break;
							q.pop_front();
							nnum+=num[x][i];
							bei.push_back(x);
						}
						while(!bei.empty()){
							ll x=bei.back();
							q.push_front(x);
							bei.pop_back();
						}
					}
				}
			}
			if(q.empty()){
				nnum=num[j+1][i];
				num[j][i]=num[j+1][i];
				dp[j][i]=1+dp[j+1][i];
			}else{
				ll x=q.front();
				if(dp[x][i]==dp[j+1][i]){
					nnum+=num[j+1][i];
					num[j][i]=nnum;
					dp[j][i]=1+dp[j+1][i];
				}else{
					num[j][i]=nnum;
					dp[j][i]=1+dp[x][i];
				}
			}
			q.push_back(j+1);
			if(num[j][i]==2)ans++;
//			cout<<j<<' '<<i<<' '<<dp[j][i]<<' '<<num[j][i]<<endl;
		}
		while(!q.empty())q.pop_back();
	}
	cout<<ans<<endl;
	ans=0;
	while(!q.empty())q.pop_front();
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
//
