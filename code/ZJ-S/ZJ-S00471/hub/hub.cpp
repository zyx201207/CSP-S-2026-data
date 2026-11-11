/*
//freopen("hub.in", "r", stdin);
//freopen("hub.out", "w", stdout);
（吸引火力和视线的靶子[嘻嘻]） 
hello hello
我是Air__one，坐标ZJ-HZ
洛谷 uid 1071851 欢迎找我玩
只是由于学业繁忙，下半学期不太会上线
(啊啊啊真的是，上午的J组没想出T4，一直在磨蹭，没时间写游记了) 
小小吐槽一下浙师范仓前的电脑，线路不太好，J组的时候连着黑屏两次，还好我保存在D盘了
所以说：
天下的出题人是一般黑 
地上的机房配置全都落了灰
胳膊稍 微 动 动 就肘人飞
谁的题目没有鬼（不可寻找不可了解不可直视的远古bug）
艾玛我真是太有才了（哦不不不这难道就是昨晚熬夜看不白吃的后果吗） 
嗯我真是个沼气蓬勃的初三生，没有退役的离愁别虚、亡国之痛、故国之死、怅然若失、文艺复兴、文思泉涌、惆怅惋惜、追忆之情、反复追忆之情、while(追忆)、思乡之情、思亲之情、思念之情、思考之情……
（突然发现退役时可以去转行当小说家，因为:
1.打字很快 
2.文思泉涌
3.情感丰富真挚
4.时间充裕（真的吗？好吧这只是用来凑4分4点的）） 
但是，好像没有但是了，18：05了我要去终检了，再不终检我将 忘开longlong 忘开freopen const范围写错 数组越界 把i写成j 引用错误变量、数组 
#include<bits/stdc++.h>
using namespace std;int main(){int_128 RP;while(1){RP++;}return 0;}
祝你RP++AK CSP-J CSP-S NOIP NOI IOI（不是在某个奇怪的网页上AK哦，虽然我好像连AC都没搞出来过） 
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long C, T, n, m, lin, ans, f[N], vis[N];
vector <int> a[N];
void DFS(int x){
	vis[x] = 1;
	for (int i = 0; i < a[x].size(); i ++){
		if (f[a[x][i]] && !vis[a[x][i]]) DFS(a[x][i]);
	}
	return ;
}
long long BFS(long long x){
	for (int i = 1; i <= n; i ++) vis[i] = 0;
	queue <int> q;
	q.push(x);
	vis[x] = 1;
	while (x --){
		x = q.front();
		q.pop();
		if (f[x] == 1) return vis[x] - 1;
		for (int i = 0; i < a[x].size(); i ++){
			if (!vis[a[x][i]]){
				q.push(a[x][i]);
				vis[a[x][i]] = vis[x] + 1;
			}
		}
	}
	return -1;
}
void MAIN(){
	cin >> n >> m, ans = 1e18;
	for (int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u); 
	}
	for (int i = 1; i < (1 << n); i ++){
		int k = 0;
		for (int j = 1; j <= n; j ++){
			if (i & (1 << (j - 1))) f[j] = 1, k ++;
			else f[j] = 0;
			vis[j] = 0;
		}
		if (k != m) continue;
		lin = 0;
		for (int j = 1; j <= n; j ++){
			if (f[j] && !vis[j]){
				DFS(j);
				lin += 1;
			}
		}
		if (lin == 2){
			lin = 0;
			for (int j = 1; j <= n; j ++) lin = max(lin, BFS(j));
			ans = min(lin, ans);
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i ++) a[i].clear();
	return ;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while (T --) MAIN(); 
	return 0;
}
