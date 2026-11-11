#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,ans,x[2000001];
pair<int,int> cnt[2000001];
bool vis[60001],specA;
vector<int> g[60001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		specA=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>2&&x[i]-x[i-1]!=1)specA=0;
			g[i].clear();
			vis[i]=0;
			cnt[i].first=0;
			cnt[i].second=1;
		}
		if(n>10000&&specA){
			if(d==1){
				cout<<"0\n";
			}
			else {
				cout<<max(0ll,n-2*d+1)<<"\n"; 
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&abs(x[j]-x[i])<=d){
					g[i].push_back(j);
					//cout<<"qqq:"<<i<<" "<<j<<"\n";
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vis[j]=0;
				cnt[j].first=0;
				cnt[j].second=1;
			}
			que.push({0,i});
			while(!que.empty()){
				auto u=que.top();
				que.pop();
				if(vis[u.second])continue;
				vis[u.second]=1;
				for(auto v:g[u.second]){
					if(vis[v])continue;
					if(cnt[v].first==0||cnt[v].first>u.first+1){
						cnt[v].first=u.first+1;
						cnt[v].second=cnt[u.second].second;
						que.push({cnt[v].first,v});
						/*
						if(i==5){
							cout<<"qwp:"<<u.second<<" "<<v<<"\n";
						}*/
					}
					else if(cnt[v].first==u.first+1){
						cnt[v].second++;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				/*
				if(i==5&&j==1){
					cout<<"ppp:"<<cnt[j].first<<" "<<cnt[j].second<<"\n";
				}*/
				if(cnt[j].second==2){
					ans++;
					//cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
