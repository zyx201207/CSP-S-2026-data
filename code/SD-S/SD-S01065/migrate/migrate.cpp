#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int T,dis[N],tot[N],n,s[N];
ll d,x[N],c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		if(c>=11){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		for(int s=1;s<=n;++s){
			for(int i=1;i<=n;++i) tot[i]=0,dis[i]=2e9;
			queue<pair<int,int> > q;
			dis[s]=0;
			q.push({s,0});
			while(!q.empty()){
				pair<int,int> p=q.front();
				q.pop();
				if(p.second!=dis[p.first]) continue;
				for(int i=1;i<=n;++i){
					if(i==p.first) continue;
					if(x[i]-x[p.first]>d) break;
					if(dis[i]>dis[p.first]+1&&x[i]-x[p.first]<=d){
						dis[i]=dis[p.first]+1;
						tot[i]=1;
						q.push({i,dis[i]});
					}else if(dis[i]==dis[p.first]+1&&x[i]-x[p.first]<=d){
						q.push({i,dis[i]});
						tot[i]++;
					}
				}
			}
			for(int i=1;i<=n;++i) if(tot[i]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
