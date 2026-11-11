#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int n,d;
int a[maxn];
int ans;
int c,t;
struct node{
	int v,cnt;
};
node dp[maxn];
void upd(int i,int j){
	int gd=dp[j].v+1;
	//cout<<i<<" "<<j<<" "<<dp[i].v<<" "<<gd<<'\n'; 
	if(dp[i].v==gd){
		dp[i].cnt+=dp[j].cnt;
	}else if(dp[i].v>gd){
		dp[i].cnt=1;
		dp[i].v=gd;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i].v=1e9;
			dp[i].cnt=0;
		}
		dp[1].v=0;
		for(int st=1;st<=n;st++){
			for(int i=st;i<=n;i++){
				dp[i].v=1e9;
				dp[i].cnt=0;
			}
			dp[st].v=0;
			for(int i=st;i<=n;i++){
				for(int j=i-1;j>=st;j--){
					if(a[i]-a[j]<=d){
						upd(i,j);
					}else{
						break;
					}
				}
			}
			for(int i=st;i<=n;i++){
				if(dp[i].cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
