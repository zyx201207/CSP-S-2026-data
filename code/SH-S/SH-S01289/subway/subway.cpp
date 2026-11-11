# include <iostream>
# include <vector>
# include <queue>
# define ull unsigned long long
# define MAXN 500010
using namespace std;
int c, n, m, d, q;
int x, y, tmp;
ull ans;
ull w[MAXN];			//进站时间 
int k[MAXN];			//i经过的地铁站数量
int a[510];			//i经过j
ull t[510][MAXN];			//地铁站j到站台i的时间 
queue<int> num[MAXN];
vector<int> G[MAXN];
bool find(int aim, int wh){
	while(aim != num[wh].front()){
		num[wh].pop();
		if(num[wh].empty()) return 0;
	}
	return 1;
}

void fi_nd(int u,int v,int st,ull cnt){
	for(int k : G[u]){
		if(find(st,k)) fi_nd(k,v,st,cnt);
		else{
			int i = num[k].front();
			while(find(i,u)){
				num[k].pop();
			}
			cnt += t[st][u] + t[i][k] + t[i][k];
			fi_nd(k,v,i,cnt);
		}
	}
	ans = min(ans, cnt);
	tmp = st;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++) cin>>w[i];
	for(int i = 1; i <= n; i++){
		cin>>k[i];
		for(int j = 1; j <= k[i]; j++){
			cin>>a[j]>>t[i][j];
			num[a[j]].push(i);
		}
		for(int j = 1; j < k[i]; j++){
			G[a[j]].push_back(a[j + 1]);
			G[a[j + 1]].push_back(a[j]);
		}
	}
	for(int i = 1; i <= q; i++){
		cin>>x>>y;
		ans = 1e+9;
		int j = num[x].front();
		while(!num[x].empty()){
			fi_nd(x,y,j,w[x]);
			num[x].pop();
		}
		ans += w[tmp];
		cout<<ans<<"\n";
	}
	return 0;
} 
