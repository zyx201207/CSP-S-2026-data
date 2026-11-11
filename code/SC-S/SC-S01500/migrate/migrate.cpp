#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int c,T;

int n;
ll d;
ll a[2000006];

void read(){
	cin >> n >> d;
	for(int i=1;i<=n;++i) cin >> a[i];
}

ll ans=0;
ll cnt[200000],cost[200000];
queue<pii>q;
void BL_work(){
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=i;k<=j;++k) cnt[k]=0,cost[k]=0;
			q.push({i,0});
			while(q.size()){
				auto root=q.front();q.pop();
				ll co=root.second,id=root.first;
				if(co < cost[id]){
					cost[id]=co;
					cnt[id]=0;
				}
				if(co == cost[id]){
					cnt[id]++;
					for(int k=id+1;a[k] - a[id] <= d;++k){
						q.push({k,co+1});
					}
				}
			}
			for(int k=1;k<=n;++k){
				if(cost[k] && cnt[k]==2)ans++;
			}
		}
	}
}

void write(){
	cout << ans <<"\n";
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	
	
	//if(c <= 10){
		while(T--){
			read();
			BL_work();
			write();
		}
		
	//}
	
	
	
	return 0;
}