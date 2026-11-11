#include<bits/stdc++.h>
using namespace std;
int c,t;
long long ans;
int n;
long long d;
int cnt[2000005];
long long dis[2000005];
long long x[2000005];
void bfs(int xt){
	queue<int> q;
	q.push(xt);
	while(!q.empty()){
		int tq=q.front();
//		cerr<<tq<<"\n";
		q.pop();
		for(int i=tq+1;i<=n;i++){
			if(i==tq)continue;
			long long twt=abs(x[i]-x[tq]);
			if(twt<=d){
				if(dis[tq]+twt<dis[i]){
					dis[i]=dis[tq]+twt;
					cnt[i]=0;
					q.push(i);
				}else if(dis[tq]+twt==dis[i]){
					cnt[i]++;
					q.push(i);
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=LONG_LONG_MAX;
				cnt[j]=0;
			}
			dis[i]=0;
			bfs(i);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}