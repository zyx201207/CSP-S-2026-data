#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],dp[200010],s[200010];
int c,t;
queue<int> q;
int ans;
struct node{
	int x,y;
};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t){
		t--;
	
		ll n,d,a[5010];cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int j=1;j<=c;j++)dp[i]=1e9,s[j]=0;
		dp[i]=0,s[i]=1;
		q.push_back{(1,0)};
		for(ll j=i+1;j<=n;j++){
			while(!q.empty()&&a[j]-a[q.front().x]>d)q.pop_front();
			vector<node>lis;
			while(!q.empty()&&q.front().y+1<=dp[j]){
				lis.push_back(q.front());
				dp[j]=q.front().y+1;s[j]+=s[q.front().x];
				q.pop_front();
			}	
			for(int k=0;k<lis.size()-1;k++){
				q.push_front();
				}
			for(ll k=0;k<lis.size();k++){
				q.push_back(j,dp[j]);
				//if(s[j]==z)ans+=1;
			}
			
		/*		if(a[j]-a[k]<d){
					if(dp[j]>dp[k]+i){
						dp[j]=dp[k]+1;s[j]=s[k];
					}
				}
				else if(dp[j]==dp[k]+1){
					s[j]+=s[k];
				}
			}
		}*/
		if(s[j]==2)ans+=1;
	}
	cout <<ans <<endl;
}
	return 0;
}