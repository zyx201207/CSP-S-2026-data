#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,long long>
long long INF = 9000000000000000ll;
long long gr[510][510];
long long walkcost[500010];
vector<pii> passby[500010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q,kt,ai,xi,yi;
	long long ti,ans;
	for(int i = 0;i<509;++i){
		for(int j = 0;j<509;++j)gr[i][j]=INF;
	}
	for(int i = 0;i<509;++i)gr[i][i]=0;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;++i)cin >> walkcost[i];
	for(int i = 1;i<=n;++i){
		cin >> kt;
		for(int j = 0;j<kt;++j){
			cin >> ai >> ti;
			passby[ai].push_back(pii(i,ti)); 
		}
	}
	for(int i = 1;i<=m;++i){
		vector<pii>& curr=passby[i]; 
		for(int d1 = 0;d1<curr.size();++d1){
			for(int d2 = 0;d2<curr.size();++d2){
				if(d1==d2) continue;
				gr[curr[d1].first][curr[d2].first]=min(
					gr[curr[d1].first][curr[d2].first],
					curr[d1].second+curr[d2].second
				);
				gr[curr[d2].first][curr[d1].first]=min(
					gr[curr[d2].first][curr[d1].first],
					curr[d1].second+curr[d2].second
				);
			}
		}
	} 
	for(int k = 1;k<=n;++k){
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=n;++j){
				gr[i][j]=min(gr[i][j],gr[i][k]+gr[k][j]);
			}
		}
	}
	for(int i = 0;i<q;++i){
		ans=INF;
		cin >> xi >> yi;
		for(int d1=0;d1<passby[xi].size();++d1){
			for(int d2=0;d2<passby[yi].size();++d2){
				ans=min(ans,
					gr[passby[xi][d1].first][passby[yi][d2].first]
					+passby[xi][d1].second+passby[yi][d2].second
				);
			}
		}
		ans+=walkcost[xi]+walkcost[yi];
		cout << ans << '\n';
	}
	return 0;
} 
