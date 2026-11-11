// SN-S00515 王铂涵 西安市铁一中
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define pq priority_queue
#define ull unsigned long long
#define ll long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define dep(i,r,l) for(int i = r; i >= l; i--)
using namespace std;
const int N = 2e6 + 5;

int n, d, x[N], C, L[N], R[N], ret[N], cnt[N];vector<int>vc[3005];
int dis(int aa, int bb){return abs(x[aa] - x[bb]);}
void clear(){} int b[3005],ds[3005];
void bfs(int x){ rep(i,1,n)ds[i]=-1,b[i]=0;
	queue<int> q;q.push(x);ds[x]=0;b[x]=1;
	while(!q.empty()){
		int y = q.front();q.pop();
		for(int z:vc[y]){
			if(~ds[z]){
				if(ds[z]==ds[y]+1)b[z]+=b[y];
				continue;
			}
			ds[z]=ds[y]+1;b[z]=b[y];q.push(z);//cout<<y<<"->"<<z<<" "<<ds[z]<<"******\n";
		}
	}
}
void solve(){
	clear();
	cin >> n >> d; rep(i, 1, n) cin >> x[i];
	int l = 1; rep(i, 1, n){ ret[i] = 0;
		while(dis(l, i) > d) ++l;
		L[i] = l;
	}
	int r = n; dep(i, n, 1){
		while(dis(r, i) > d) --r;
		R[i] = r;
	} int res = 0;
	if(C <= 10){
		rep(i,1,n)rep(j,1,n)if(dis(i,j)<=d)vc[i].pb(j);//,cout<<i<<" "<<j<<"\n";
		rep(i,1,n){
			bfs(i);rep(j,1,n)res+=(b[j]==2);//,cout<<i<<" "<<j<<"="<<b[j]<<"\n";
		}cout<<res/2<<"\n"; rep(i,1,n)vc[i].clear();return; 
	}
	rep(i, 1, n){ // cout << i << ":" << L[i] << " " << R[i] << "\n";
		int l1 = L[i] + 1, l2 = L[i] + 2, r1 = R[i] - 1, r2 = R[i] - 2; cnt[i] = cnt[i - 1] + 1;
		if(l2 <= i){
			ret[i] += cnt[L[l2] - 1] - cnt[L[l1] - 1];
//			if(L[l2] - L[l1]) cout << i << "->" << l1 << " " << L[l1] << "   " << l2 << " " << L[l2] << "\n"; 
		}
//		if(r2 >= i){
//			ret[i] += R[r1] - R[r2];
////			if(R[r1] - R[r2]) cout << i << "->" << r1 << " " << R[r1] << "   " << r2 << " " << R[r2] << "\n"; 
//		}
		if(L[i] != i){
			ret[i] += ret[L[i]]; cnt[i] += cnt[L[i]] - cnt[L[i] - 1];
//			l1 = L[L[i]] + 1; l2 = L[L[i]] + 2;
			
		}
	} rep(i, 1, n) res += ret[i]; cout << res << "\n";
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T = 1;
	cin >> C >> T;
	while(T--) solve();
}

