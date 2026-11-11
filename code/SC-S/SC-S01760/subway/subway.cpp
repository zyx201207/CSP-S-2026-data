#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int N=5e5+5;
const int M=505;
const int INF=1e18;
int O,n,m,d,q,w[N],ans,dis[M][M];
vector<pii>hav[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>O>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int tot;
		cin>>tot;
		for(int j=1;j<=tot;j++){
			int x,y;
			cin>>x>>y;
			hav[x].eb(i,y);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		for(pii j:hav[i]){
			for(pii k:hav[i]){
				dis[j.fir][k.fir]=min(dis[j.fir][k.fir],j.sec+k.sec);
				dis[k.fir][j.fir]=min(dis[k.fir][j.fir],j.sec+k.sec);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		ans=INF;
		for(pii i:hav[l]){
			for(pii j:hav[r]){
				ans=min(ans,dis[i.fir][j.fir]+i.sec+j.sec+w[l]+w[r]);
			}
		}
		cout<<ans<<'\n';
	}
}