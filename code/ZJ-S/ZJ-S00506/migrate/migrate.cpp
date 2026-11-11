#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 5e3+5;
struct Node{
	LL v,w;
	vector<LL> pa;
	bool operator < (const Node &cmp)const{
		return w < cmp.w;
	}
};
LL c,t,a[MAXN];
//dijkstra
vector<LL> paths[MAXN];
inline bool bfs(LL srt,LL dst){
	priority_queue<Node> q;
	q.push({srt,0,{}});
	LL cnt = 0,lm = 0;
	while(!q.empty()){
		LL ui = q.top().v,di = q.top().w;
		vector<LL> pai = q.top().pa;
		q.pop();
		for(auto ch:pai){
			if(ch == ui) continue;
		}
		pai.push_back(ui);
		if(ui==dst){
			if(cnt == 0){
				cnt++;
				lm = -di;
			}
			else if(cnt == 1){
				if(-di == lm) cnt++;
				else return 0;
			}
			else{
				if(-di == lm) return 0;
				else return 1;
			}
		}
		for(auto vi: paths[ui]){
			q.push({vi,di-1,pai});
		}
	}
	if(cnt == 2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		LL n,d,ans=0;
		cin >> n >> d;
		memset(paths,{},sizeof(paths));
		for(LL i = 1;i <= n;i++){
			cin >> a[i];
			for(LL j = i-1;j > 0;j--){
				if(a[i]-a[j] <= d){
					paths[i].push_back(j);
					paths[j].push_back(i);
				}
				else break;
			}
		}
		for(LL i = 1;i < n;i++){
			for(LL j = i+1;j <= n;j++){
				ans += bfs(i,j);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
