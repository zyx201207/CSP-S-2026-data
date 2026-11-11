#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSPS cout.tie(0);
#define handin 0
int c,t,n,d,x[314],cnt;
pair<int,int> dist[314][314];
inline void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(llabs(x[i]-x[j])<=d){
					dist[i][j].first=min(dist[i][j].first,dist[i][k].first+dist[k][j].first);
					dist[i][j].second=1;
				}
				else{
					dist[i][j].first=(dist[i][k].first+dist[k][j].first);
					dist[i][j].second=1;
				}
			}
		}
	}
	return;
}
inline int floyd2(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j].first==dist[i][k].first+dist[k][j].first&&dist[i][j].second==1){
					cnt++;
				}
			}
		}
	}
	return cnt;
}
signed main(){
	I AK CSPS
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j].first=0x3f3f3f3f3f3f3f3f;
				dist[i][j].second=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(llabs(x[i]-x[j])<=d){
					dist[i][j].first=llabs(x[i]-x[j]);
				}
			}
		}
		cnt=0;
		floyd();
		cout<<floyd2()<<'\n';
	}
	return 0;
}
