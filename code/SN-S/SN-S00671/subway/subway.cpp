#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000005;
const int M = 5005;
int c,n,m,d,q,w[N],dis[N],cur,vis[N],f[M][M];
int read(){
	int ans = 0;
	char c;
	c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9'){
		ans = (ans*10)+c-'0';
		c = getchar();
	}
	return ans;
}
struct node{
	int x,y;
	bool operator<(const node x)const{
		return y < x.y;
	}
};
vector<node> vec[N];
//void dij(int s){
//	priority_queue<node> q;
//	q.push({s,0});
//	dis[s] = 0;
//	while(!q.empty()){
//		node p = q.top();
//		q.pop();
//		if(vis[p.x])
//			continue;
//		vis[p.x] = 1;
//		for(int i = 0;i < vec[p.x].size();i++){
//			node o = vec[p.x][i];
//			if(dis[o.x] > p.y + o.y){
//				dis[o.x] = p.y + o.y;
//				q.push({o.x,dis[o.x]});
//			}
//		}
//	}
//	return;
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	system("fc subway.out subway7.ans");
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= 500;i++)
		for(int j = 1;j <= 500;j++)
			f[i][j] = 1145141919810;
	for(int i = 1;i <= 500;i++)
		f[i][i] = 0;
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	cur = m;
	for(int i = 1;i <= m;++i)
		w[i] = read();
	for(int i = 1;i <= n;++i){
		int k;
		k = read();
		for(int j = 1;j <= k;++j){
			int a,b;
			a = read();
			b = read();
			vec[a].push_back({i,b});
		}
	}
	for(int i = 1;i <= m;++i){
		int sz = vec[i].size();
		for(int j = 0;j < sz;j++)
			for(int k = 0;k < sz;k++){
				int u1 = vec[i][j].y,u2 = vec[i][k].y;
				f[vec[i][j].x][vec[i][k].x] = min(f[vec[i][j].x][vec[i][k].x],u1+u2);
			}
	}
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
//	for(int i = 1;i <= n;i++)
//		for(int j = 1;j <= n;j++){
//			cout << i << " 到 " << j << " 是 " << f[i][j] << '\n';
//		}
//	dij(1);
	for(int i = 1;i <= q;i++){
		int qq,z;
		qq = read();
		z = read();
		int minn = LONG_LONG_MAX;
		int s1 = vec[qq].size(),s2 = vec[z].size();
		for(int i = 0;i < s1;i++)
			for(int j = 0;j < s2;j++)
				minn = min(minn,f[vec[qq][i].x][vec[z][j].x]+vec[qq][i].y+vec[z][j].y);
		cout << minn+w[qq]+w[z] << '\n';
	}
	return 0;
}
/*

CCF Just_do_it.png
luoguID:Flynewcat
尽管我无法证明它的对错，但我坚信它是对的！ 
*/
