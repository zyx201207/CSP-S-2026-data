#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
long long c,t;
int main(){
	fast;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		long long x[n+10],dp[n+10],ans[n+10],sum;
		vector<pair<long long,long long>> g[n+10];
		long long xx;
		bool f=false;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		xx=x[2]-x[1];
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=xx){
				f=true;
			}
		}
		if(f==false){
			if(d>2*xx){
				cout<<0<<endl;
				continue;
			}
			else{
				cout<<max(n-(d+1),0ll)<<endl;
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back({j,x[j]-x[i]});
				}
				else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			memset(dp,0x3f,sizeof(dp));
			for(int j=1;j<=n;j++){
				ans[j]=0;
			}
			dp[i]=0;
			ans[i]=1;
			priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
			q.push({0,i});
			while(!q.empty()){
				long long y=q.top().second;
				long long x=q.top().first;
				q.pop();
				if(x>dp[y]){
					continue;
				}
				for(auto i:g[y]){
					long long j=i.first;
					long long l=i.second;
					if(dp[y]+l<dp[j]){
						dp[j]=dp[y]+l;
						ans[j]=ans[y];
						q.push({dp[j],j});
					}
					if(dp[y]+l==dp[j]){
						ans[j]=ans[y]+1;
						q.push({dp[j],j});
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(ans[j]==2){
					sum++;
				}
			}
		}
		cout<<sum/n<<endl;
	}
	return 0;
}
