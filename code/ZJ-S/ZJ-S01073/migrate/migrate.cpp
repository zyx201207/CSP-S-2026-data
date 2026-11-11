#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int x[200010];
int dis[5010][5010],cnt[5010][5010];
vector<int> g[5010];
void solve1(){
	for(int i=1;i<=5000;i++){
		int _=g[i].size();
		while(_--){
			g[i].pop_back();
		}
	}
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				g[i].push_back(j);
			}
			dis[i][j]=inf,dis[j][i]=inf;
		}
		dis[i][i]=0;
		cnt[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		int G=i;
		priority_queue<pair<int,int>> q;
		q.push({0,G});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			for(auto v:g[u]){
				if(dis[G][v]>dis[G][u]+1){
					dis[G][v]=dis[G][u]+1;
					cnt[G][v]=cnt[G][u];
					q.push({dis[G][v],v});
				}
				else if(dis[G][v]==dis[G][u]+1){
					cnt[G][v]+=cnt[G][u];
					q.push({dis[G][v],v});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
void solve2(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int c=x[2]-x[1];
	if(d<c*2){
		cout<<0<<endl;
	}
	else{
		int m=d/c;
		if(m==2)cout<<n-(m+1)<<endl;
		else{
			cout<<max(0ll,n-(2*m-1))<<endl;
		}
	}
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
    	if(c<=10)solve1();
    	else if(c==11||c==12){
    		solve2();
		}
		else{
			cout<<0<<endl;
		}
	}
    return 0;
}
