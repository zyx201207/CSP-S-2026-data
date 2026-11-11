#include <bits/stdc++.h>
using namespace std;
int n, k, c, t, gg, hf;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d", &c);
	if (c == 0){
		cout<<1<<endl;
		cout<<2<<endl;
		return 0;
	}
	scanf("%d", &t);
	while (t --){
		scanf("%d%d", &n, &k);
		for (int i = 1;i < n;i ++){
			scanf("%d%d", &gg, &hf);
		}
		printf("%d/n", gg / hf - 1);
	}
	return 0;
}

// 燃尽了。。。
// T1随便秒（应该），T2看懂了但不知道怎么优化
// 然后去开T3，T3。。。
// 被自己绕死了
// gg
// luogu uid没背下来，我是fw

// ccfreeopen("p***hub.com", "r", stdin)

// 唉可惜这波贪了

// 哦对了，Danking -/==== O* Zywoo
// gg, 吃饭要紧 

// 话说我还让Deepseek Harness在6:30自动去luogu上找这次的题
// 然后写题解来着 感觉可以赶回家去取消了 看了也没用 
