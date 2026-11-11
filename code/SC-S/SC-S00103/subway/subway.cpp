#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
 
int w[(int)5e+5+10]; // 时间从地铁口到站厅
int LineHSH[500+10][(int)5e+5+10]; // 线路拥有哪些站，[0]是线路有多少个站 
struct EachStation{
	int k; // 所容线数量
	int cl[20+10]; // 所容线编
	int t[20+10]; // 时间从站厅到站台，按照线编
} l[(int)5e+5+10];

bool query(int stationA, int stationB, int &a, int &b) {
	for (int i=1; i<=l[stationA].k; i++) {
		for (int j=1; j<=l[stationB].k; j++) {
			if (l[stationA].cl[i] == l[stationB].cl[j]) {
				a = i, b = j;
				return true;
			}
		}
	}
	return false;
}

void search(int start, int stops, int cnt, int anti, bool &I_SAID_EXIT) {
	// 确定是不是在一根线上
	int k1, k2; 
	if (query(start, stops, k1, k2)) {cnt+=l[start].t[k1]+l[stops].t[k2]; cout<<cnt<<endl; I_SAID_EXIT = true; return;}
	
	// 枚举出发点的线路，在每条所选线上寻找一个除了起点以外的换乘站 
	for (int i=1; i<=l[start].k; i++) {
		int &line = l[start].cl[i]; // 当前线编
		if (line == anti) continue; // 防呆机制
		
		cnt += l[start].t[i];
		for (int j=1; j<=LineHSH[line][0]; j++) {
			int &target = LineHSH[line][j]; // 当前站
			if (target == start) continue; // 排除自己
			if (l[target].k == 1) continue; // 排除非换乘站
			// 现在找到一个换乘站
			int findsout = 0;
			for (int k=1; k<=l[target].k; k++) {
				if (l[target].cl[k] == line) findsout = k;
			}
			cnt += l[target].t[findsout]; // 当前线路回到站厅
			search(target, stops, cnt, line, I_SAID_EXIT); // 执行一次换乘操作
											  // 最后的是为了防止无限套娃，刚刚左过的线路就不能在乘坐
			if (I_SAID_EXIT == true) return; //找到答案了就出去
			cnt -= l[target].t[i]; // 回溯
		}
		cnt -= l[start].t[i];
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int *c = new(int), n, m, d, q; cin>>*c>>n>>m>>d>>q; free(c);
	memset(l, 0, sizeof(l));
	for (int i=1; i<=m; i++) cin>>w[i];
	for (int i=1; i<=n; i++) {
		int k; cin>>k;
		LineHSH[i][0] = k;
		for (int j=1; j<=k; j++) {
			int a, t; cin>>a>>t;
			l[a].k++;
			l[a].cl[l[a].k] = i;
			l[a].t[l[a].k] = t;
			LineHSH[i][j] = a;
		}
	}
	
	while (q--) {
		int starts, stops; cin>>starts>>stops;
		int cnt=w[starts]+w[stops]; // 总和：初始
		
		bool tmp = false;
		search(starts, stops, cnt, -1, tmp);
	}
	return 0;
}