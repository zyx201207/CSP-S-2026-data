#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int maxn=5005;
const int inf=1e18;
int c,t,n,d,x[maxn];
pii dp[maxn][maxn];
struct subtask1_solver{
	void solve(){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			memset(dp,0,sizeof dp);
			for(int i=1;i<=n;i++){
				dp[i][i]={0,1};
				for(int j=i+1;j<=n;j++){
					int mn=inf,sum=0;
					for(int k=j-1;k>=i;k--){
						if(x[j]-x[k]>d)break;
						if(dp[i][k].first<mn){
							mn=dp[i][k].first;
							sum=dp[i][k].second;
						} else if(dp[i][k].first==mn){
							sum+=dp[i][k].second;
						}
					}
					dp[i][j]={mn+1,sum};
				}
			}
			int ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(dp[i][j].second==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		return;
	}
}sub1;
struct subtask2_solver{
	void solve(){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			memset(dp,0,sizeof dp);
			for(int i=1;i<=n;i++){
				deque<int> que;
				int sum=0;
				dp[i][i]={0,1};
				for(int j=i+1;j<=n;j++){
					while(!que.empty()){
						if(dp[i][que.back()].first>dp[i][j-1].first){
							que.pop_back();
						} else {
							break;
						}
					}
					que.push_back(j-1);
					if(que.size()==1){
						sum=dp[i][j-1].second;
					}
					while(!que.empty()){
						if(x[j]-x[que.front()]>d){
							sum-=dp[i][que.front()].second;
							que.pop_front();
						} else {
							break;
						}
					}
					if(sum<=0){
						sum=0;
						if(!que.empty()){
							int mn=dp[i][que.front()].first;
							for(int k=que.front();k<j;k++){
								if(dp[i][k].first==mn)sum+=dp[i][k].second;
							}
						}
					}
					if(!que.empty()){
						dp[i][j]={dp[i][que.front()].first+1,sum};
					} else {
						dp[i][j]={-1,0};
					}
				}
			}
			int ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(dp[i][j].second==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		return;
	}
}sub2;
struct subtask3_solver{
	void solve(){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int dx=x[2]-x[1];
			int num=d/dx;
			if(num==2){
				cout<<n-3<<endl;
			} else cout<<0<<endl;
		}
		return;
	}
}sub3;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(1<=c&&c<=6)sub1.solve();
	if(7<=c&&c<=10)sub2.solve();
	if(11<=c&&c<=12)sub3.solve();
	return 0;
}