#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,pos[2145141],c,T,d,dis[2145141],cnt[2145141],ans;
vector<ll> ad[2145141];
queue<ll> q;
map<pair<int,int>,int> mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	T++;
	while(--T){
		cin>>n>>d;
		ans=0;
		for(ll i=1;i<=n;i++){
			dis[i]=214514144;
			cnt[i]=0;
			cin>>pos[i];
			ad[i].clear();
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				//cout<<pos[j]-pos[i]<<" "<<d<<endl;
				if(pos[j]<=d+pos[i]){
					ad[j].push_back(i);
					ad[i].push_back(j);
				}else{
					break;
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dis[j]=214514441;
				cnt[j]=0;
			}
			q.push(i);
			dis[i]=0;
			while(!q.empty()){
				ll p=q.front();
				q.pop();
				for(int j=0;j<ad[p].size();j++){
					int v=ad[p][j];
					if(dis[v]>dis[p]+1){
						cnt[v]=1;
						dis[v]=dis[p]+1;
						q.push(v);
					}else if(dis[v]==dis[p]+1){
						cnt[v]++;
						q.push(v);
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(cnt[i]==2)ans++;
			}
		}
		cout<<ans/2<<endl;
	}

	return 0;
}

