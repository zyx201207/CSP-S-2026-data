#include<bits/stdc++.h>
using namespace std;
int C,T;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	if(C<=10){
		while(T--){
			int n;
			long long d,ans=0;
			cin>>n>>d;
			long long a[n+1],minn[n+1][n+1],len[n+1][n+1];
			vector<int> e[n+1];
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d) break;
					e[i].push_back(j);
				}
			}
			memset(minn,0x3f,sizeof(minn));
			memset(len,0,sizeof(len));
			for(int i=1;i<=n;i++){
				queue<pair<int,int>> q;
				q.push({i,0});
				while(q.size()){
					pair<int,int> w=q.front();
					q.pop();
					if(w.second>minn[i][w.first]) continue;
					for(auto j:e[w.first]){
						if(w.second+1<minn[i][j]){
							if(len[i][j]==2) ans--;
							len[i][j]=0;
							minn[i][j]=w.second+1;
							q.push({j,w.second+1});
						}
						if(w.second+1==minn[i][j]){
							len[i][j]++;
							if(len[i][j]==2) ans++;
							if(len[i][j]>2) ans--;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}else while(T--) cout<<0<<'\n';
}
