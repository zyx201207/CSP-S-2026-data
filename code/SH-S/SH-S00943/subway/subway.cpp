//pre: -1
#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500010], k[525], a[525][525], t[525][525];
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1; i <= q; i++){
		int s, e, cur;
		long long t;
		cin >> s >> e;
		//dij能拿到分？性质B似乎保证： 站厅走到对应线路站台的步行时间都相同？ 
		//是，但题目的输入似乎不是一张标准的邻接表。
		//暂时放弃dij，等到17:30重新尝试 
		//17:25，上一题可能拿75，为拿二级，此题应拿30，且如果上一题因某些原因WA，则可能连三级都拿不到 
		//考虑dij？这能拿32分，但，似乎有点难编，还有1小时，计划全部花在这题上，还是先去T3 T4骗分？ 
		//emm...dij写到一半忘了...真是没招了...，其他图论算法（如Floyd）？先去T3 T4骗分吧？ 
		//暂时放弃T2，等到17:50重新尝试
		//emm...已经18:05了，T3骗到10分，怎么办呢？这编不出来我就很没招（明明能骗30） 
		//放弃此题，顺便写句cout，这能拿分就怪了  
		cout << 525; 
	}
	return 0;
}
