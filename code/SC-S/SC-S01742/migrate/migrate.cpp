#include<bits/stdc++.h>
using namespace std;
//我们有一种n^3的做法 枚举一个点 使用dp求出剩下点到他的最短路径和路径数
long long c,t;
struct node{
	long long x,y;//位置和数值
};
long long a[2000011],dp[2000011],s[2000011];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		long long n,d,ans=0;cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		for(long long i=1;i<=n;i++){
			deque<node>q;
			dp[i]=0,s[i]=1;
			q.push_back({i,0});
			for(long long j=i+1;j<=n;j++){
				dp[j]=1e18;s[j]=0;
				while(!q.empty()&&a[j]-a[q.front().x]>d)q.pop_front();
				vector<node>lis;
				while(!q.empty()&&q.front().y+1<=dp[j]){
					lis.push_back(q.front());
					dp[j]=q.front().y+1;s[j]+=s[q.front().x];
					q.pop_front();
				}
				if(!lis.empty()){
					for(long long k=lis.size()-1;k>=0;k--){
						q.push_front(lis[k]);
					}
				}
				while(!q.empty()&&q.back().y>dp[j])q.pop_back();
				q.push_back({j,dp[j]});
				if(s[j]==2)ans+=1;
				if(dp[j]==1e18)continue;
			}
		}
		cout<<ans<<endl;
	}
}