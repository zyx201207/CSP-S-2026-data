#include<bits/stdc++.h>
using namespace std;
long long a[2000007];
vector<int > e[5001];
int dis[5001];
void solve(){
	int n;
	long long d;
	cin>>n>>d;
	vector<int> e[5001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d) continue;
			e[i].push_back(j);
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(auto it:e[i]){
//			cout<<it<<" ";
//		}
//		cout<<"\n";
//	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			memset(dis,0x7f,sizeof(dis));
			queue<pair<int,int> > q;
			q.push({0,i});
			dis[i]=0;
			int cnt,minn=1e9;
			while(!q.empty()){
				auto t=q.front();
				q.pop();
				if(t.second==j&&t.first==minn){
					cnt++;
				}
				if(t.first<minn){
					cnt=1;
					minn=t.first;
				}
				for(const auto &it:e[t.second]){
					if(dis[it]>dis[t.second]+1){
						dis[it]=dis[t.second]+1;
						q.push({dis[it],it});
					}
				}
			}
//			cout<<"\n"<<cnt<<"\n";
			if(cnt==2){
				ans++;
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/