#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

struct il{
	int v;
	int stp;
	operator < (const il b) const{
		return stp>b.stp;
	}
};

int _,t,n,dis[2000010];
ll d,x[2000010],cnt[2000010];
vector<il> e[2000010];

void dj(int sx){
	priority_queue<il> q;
	q.push({sx,0});
	dis[sx]=0;
	while(!q.empty()){
		il k=q.top();q.pop();
		for(auto it:e[k.v]){
			if(dis[it.v]>=dis[k.v]+1){
				dis[it.v]=dis[k.v]+1;
				q.push({it.v,dis[it.v]});
				cnt[it.v]++;
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>_>>t;
	while(t--){
		for(int i=1;i<=n;i++) e[i].clear();
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d) e[j].push_back({i,1});
			}
		}
		for(int i=1;i<=n;i++){
			memset(dis,0x3f,sizeof dis);
			memset(cnt,0,sizeof cnt);
			dj(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
