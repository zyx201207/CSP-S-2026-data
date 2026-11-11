#include <bits/stdc++.h>

using namespace std;
const int MAXN = 520, MAXS = 5e5 + 20;
int c, n, stage, max_ins, k;
int arrin[MAXN] = {};
int sidecnt = 0;
int root[MAXN];
struct side{
	int s, e, v;
};
bool cmp(side a, side b){
	return a.v, b.v;
}
side sides[MAXS];
int ezmap[MAXN][MAXN] = {};
int find(int a){
	if(root[a] == a) return a;
	return root[a] = find(root[root[a]]);
}
void mapping(){
	for(int i = 1; i <= n; i++) root[i] = i;
	sort(sides + 1, sides + sidecnt + 1, cmp);
	for(int i = 1; i <= sidecnt; i++){
		if(find(sides[i].s) != find(sides[i].e)){
			root[sides[i].s] == sides[i].e;
			ezmap[sides[i].s][sides[i].e] = sides[i].v;
			ezmap[sides[i].e][sides[i].s] = sides[i].v;
			//cout << sides[i].s << ' ' << sides[i].e << ' ' << sides[i].v << endl;
		}
	}
}
int pass[MAXN] = {};
int distance(int a, int b){
	int ans = 0, mindis = 2e9, minno = 0;
	if(ezmap[a][b] != 0){
		return ezmap[a][b];
	}
	for(int i = 1; i <= n; i++){
		if(ezmap[a][i] != 0 and pass[i] == 0){
			pass[i] = 1;
			return ezmap[a][i] + distance(i, b);
		}
//		if(ezmap[a][i] != 0 and pass[i] == 0){
//			if(ezmap[a][i] < mindis){
//				mindis = ezmap[a][i];
//				minno = i;
//			}
//		}
//		pass[minno] = 1;
//
//		return ezmap[a][minno] + distance(minno, b);
	}
}
int tempdest[MAXS] = {}, temptime[MAXS] = {};
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> stage >> max_ins >> k;
	for(int i = 1; i <= stage; i++){
		cin >> arrin[i];
	}
	
	for(int i = 1; i <= n; i++){
		int cont, ways = 0;
		cin >> cont;
		for(int j = 1; j <= cont; j++){
			ways++;
			cin >> tempdest[j] >> temptime[j];
//			cout << cont << endl;
		}
		for(int a = 1; a <= cont; a++){
			for(int b = a + 1; b <= cont; b++){
				sidecnt++;
				sides[sidecnt] = {tempdest[a], tempdest[b], temptime[a] + temptime[b]};
			}
		}
	}
	mapping();
	for(int i = 1; i <= k; i++){
		int start, end;
		cin >> start >> end;
		for(int i = 1; i <= n; i++) pass[i] = 0;
		int directd = distance(start, end);
		
		cout << directd + arrin[start] + arrin[end] << endl;
		ezmap[start][end] = directd;
	}
//	cout << distance(1, 2) << ' ' << distance(2, 3) << ' ' << distance(3, 6) << ' ' << distance(1, 6);

} 
