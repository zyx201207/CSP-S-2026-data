#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
using namespace std;

const int N=3e2 + 5,INF=9e18,M=2e6 + 5;
int a[M],reach[M],dist[N][N],cnt[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t,n,d;
	cin >> c >> t;
	if(c <= 6){
		while(t--){
			cin >> n >> d;
			for(int i=1;i <= n;i++){
				for(int j=1;j <= n;j++){
					dist[i][j]=INF;
					cnt[i][j]=0;
				}
			}
			for(int i=1;i <= n;i++){
				cin >> a[i];
			}
			queue<int> q;
			for(int i=1;i <= n;i++){
				q.push(i);
				dist[i][i]=0,cnt[i][i]=1;
				while(!q.empty()){
					int u=q.front();
					q.pop();
					for(int j=1;j <= n;j++){
						if(i == j || abs(a[u] - a[j]) > d){
							continue;
						}
						if(dist[i][u] + 1 < dist[i][j]){
							dist[i][j]=dist[i][u] + 1;
							cnt[i][j]=cnt[i][u];
							q.push(j);
						} else{
							if(dist[i][u] + 1 == dist[i][j]){
								cnt[i][j]+=cnt[i][u];
							}
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i <= n - 1;i++){
				for(int j=i + 1;j <= n;j++){
					if(cnt[i][j] == 2){
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
	}
	if(c == 11 || c == 12){
		while(t--){
			int n,d;
			cin >> n >> d;
			for(int i=1;i <= n;i++){
				cin >> a[i];
			}
			int delta=a[2] - a[1];
			int range=d / delta;
			if(range <= 1){
				cout << 0 << endl;
			} else{
				cout << max(n - (2 * range - 1),0ll) << endl;
			}
		} 
	}
	if(c == 13 || c == 14){
		while(t--){
			int n,d;
			cin >> n >> d;
			for(int i=1;i <= n;i++){
				cin >> a[i];
			}
			int l,r;
			for(int i=1;i <= n;i++){
				if(a[n] - a[i] <= d){
					l=i;
					break;
				}
			}
			for(int i=n;i >= 1;i--){
				if(a[i] - a[1] <= d){
					r=i;
					break;
				}
			}
			if(l == 1 || r == n){
				cout << 0 << endl;
				continue;
			}
			for(int i=1;i <= l - 1;i++){
				int L=i,R=n,MID,ANS;
				while(L <= R){
					MID=L + (R - L) / 2;
					if(a[MID] - a[i] <= d){
						ANS=MID;
						L=MID + 1;
					} else{
						R=MID - 1;
					}
				}
				reach[i]=ANS;
			}
			for(int i=n;i >= r + 1;i--){
				int L=1,R=i,MID,ANS;
				while(L <= R){
					MID=L + (R - L) / 2;
					if(a[i] - a[MID] <= d){
						ANS=MID;
						R=MID - 1;
					} else{
						L=MID + 1;
					}
				}
				reach[i]=ANS;
			}
			int L=1,R=r + 1;
			int ans=0;
			while(true){
				int rL=reach[L],lR=reach[R];
				if(rL - lR + 1 > 2){
					R++;
				}
				if(rL - lR + 1 < 2){
					L++;
				}
				if(rL - lR + 1 == 2){
					ans++;
					L++;
					R++;
				}
				if(R == n + 1 || L == l){
					break;
				}
			}
			cout << ans;
		}
	}
	return 0;
}