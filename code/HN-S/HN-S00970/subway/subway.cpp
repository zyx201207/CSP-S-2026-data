#include<bits/stdc++.h>
#define def(i,a,b) for(i32 i = a;i <= b;i ++)
#define udef(i,a,b) for(i32 i = a;i >= b;i --)
#define Max(a,b) (a = max(a,b))
#define Min(a,b) (a = min(a,b))
#define fi first
#define se second
using namespace std;
using i32 = int;
using i63 = long long;
using pii = pair<i63,i63>;
const i63 N = 5e5 + 560,INF = 4e18,mod = 998244353;
i32 c,n,m,d,q,x,y,z;
i32 p[N];
vector<pii>a[N];
vector<i63>dit[501];
void djs(i32 s){
	dit[s][s] = 0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	while(!q.empty()){
		pii u = q.top();
		q.pop();
		if(u.fi != dit[s][u.se]) continue;
		for(pii v : a[u.se]){
			if(v.se + dit[s][u.se] < dit[s][v.fi]) {
				dit[s][v.fi] = v.se + dit[s][u.se];
				q.push({dit[s][v.fi],v.fi});
			}
		}
 	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	def(i,1,m) cin >> p[i];
	def(i,1,n){
		cin >> z;
		while(z--){
			cin >> x >> y; 
			x += n;
			a[x].push_back({i,y});
			a[i].push_back({x,y});
		}
	}
	def(i,1,n) dit[i].resize(n + m + 1);
	def(i,1,n) def(j,1,n + m) dit[i][j] = INF;
	def(i,1,n) djs(i); 
	while(q --){
		i63 res = INF;
		cin >> x >> y;
		x += n,y += n;
		for(pii v : a[x]){
			Min(res,v.se + dit[v.fi][y]);
		}
		res += p[x - n] + p[y - n];
		cout << res << '\n'; 
	}
	return 0;
}
/*
看一下 代码与实际用途是否一致 如缩点后应使用缩点后的图b[i]
注意手打hack对拍 然后对症下要特判
谨防RE 队列一定要判非空 一定要判边界
没事别全开 long long
该break时别continue
备份备份 别一顿乱搞后该不如之前的
部分分 部分分
算一下会不会MLE
*/

