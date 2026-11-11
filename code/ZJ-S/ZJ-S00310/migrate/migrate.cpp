#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t,a[2000005],vis[2000005],ans,minn,n,d;
map<int,vector<ll>> maz;

void dfs(ll x,ll v,ll sum){
	if(sum>minn){
		return ;
	}
	if(x>v){
		return ;
	}
	if(x==v){
		minn = min(minn,sum);
		vis[sum]++;
		return ;
	}
//	cout << 1 << endl;
	for(auto i:maz[x]){
		dfs(i,v,sum+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
//		cout << vis[2];
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d){
					break;
				}
				maz[i].push_back(j);
			}
		}
//		cout << maz[1].size();
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				memset(vis,0,sizeof(vis));
				minn = 200005;
				dfs(i,j,0);
				/*if(i==2&&j==5){
					cout << vis[minn] << endl;
				}*/
				if(vis[minn]==2){
					ans ++;
//					cout << i << " " << j << endl;
				}
			}
		}
		cout << ans << endl;
		for(int i=0;i<=n;i++){
			maz[i].erase(maz[i].begin(),maz[i].end());
		}
	}
	return 0;
}
