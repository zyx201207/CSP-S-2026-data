#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],f[500005],b[500005],e[500005][25],best[500005];
struct node{int x,s,line;};
vector<vector<int> > a,t;
node start,finish;
queue<node> p;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			e[j][b[a[i][j]]] = i;
			b[a[i][j]]++;
		}
	}
	for(int i = 1;i <= q;i++){
		memset(best,0x3f,sizeof(best));
		while(!p.empty()) p.pop();
		cin >> start.x >> finish.x;
		start.s = w[start.x];
		finish.s = 0;
		node y = start;
		for(int i = 1;i < b[y.x];i++){
			node l;
			l.line = e[y.x][i];
			if(l.line != y.line){
				l.s = y.s + t[y.line][y.x] + t[l.line][y.x];
			}
			else l.s = y.s;
			if(l.s < best[l.x]){
				p.push(l);
				best[l.x] = l.s;
			}
		}
		while(!p.empty()){
			node y = p.front();
			p.pop();
			for(int i = 1;i < b[y.x];i++){
				node l;
				l.line = e[y.x][i];
				if(l.line != y.line){
					l.s = y.s + t[y.line][y.x] + t[l.line][y.x];
				}
				else l.s = y.s;
				if(l.s < best[l.x]){
					p.push(l);
					best[l.x] = l.s;
				}
			}
		}
		cout << best[finish.x] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
