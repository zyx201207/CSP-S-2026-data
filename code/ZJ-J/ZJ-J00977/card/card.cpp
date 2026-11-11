#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010], anxt[500010], ans[500010];
int islr[300010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	memset(anxt, -1, sizeof(anxt));
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(islr[a[i]]) {
			anxt[islr[a[i]]] = i;
			islr[a[i]] = 0;
		}
		islr[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) { //��Ϸ���� 
		for(int j = i; j <= n; j++) { //�����Ƶı�� 
			if(anxt[j] == -1) { //û�г��� 
				ans[a[j]]++; //�ض����� 
				continue;
			}
			j = anxt[j] - 1;
		}
	}
	for(int i = 1; i <= m; i++) {
		printf("%d ", ans[i]);
	}
	cout << endl;
	return 0;
} 





























//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//ccf 	rp++
//please J1= S2=
//all chinese please use VSCode to open 
//I'm not sure witch code of chinese will use on the computer in the test place
//so just try more 
//luogu nickname JonnynbZLY
//wo yao shang da shang
//wo bu que ding ta de bian ma
//duo shi ji ge
//我要上大赏！我要上大赏！luogu名JonnynbZLY 
//我要上大赏！我要上大赏！luogu名JonnynbZLY 
//我要上大赏！我要上大赏！luogu名JonnynbZLY 
//我要上大赏！我要上大赏！luogu名JonnynbZLY 
//我要上大赏！我要上大赏！luogu名JonnynbZLY 
//我要上大赏！我要上大赏！luogu名JonnynbZLY 
//我要上大赏！我要上大赏！luogu名JonnynbZLY 
//8:55 T1 done
//8:58 T2开始
//9:00 这道题好阴啊，怎么还要运算，不能string += c 
//9:04 完了没J1=了啊，最后一题啥玩意，T3又是个DP 
//9:09 这T2怎么这么阴啊！ 
//9:13 双指针？ 
//9:19 要不a<=1e9先不要了？ 
//9:20 先把暴力打了
//9:25 暴力写完了 
//9:26 暴力1e9完全过不了啊 
//9:28 其他都能过，8个点的话32分，还有68分，先写别的题吧 
//9:30 T3开始
//9:33 我去了这是不是DP啊 
//9:36 完了不会写，n^2暴力吧 
//9:37 不对，二进制位，我取尽量多个2^k的数 
//9:39 处理二进制！每个数转成二进制然后从大位往小位扫，看最大的有m个1的地方 
//9:58 写起来还是有点麻烦的 
//10:24 大样例3不对，其他都对了，太奇怪了 
//10:51 wocnb 我调出来了！手调2000n 2^20ai大样例！！！！！ 
//10:54 又都测了一遍，全a了，应该不会超时，准备打T4，T2先放着吧 
//10:56 开始T4 
//11:02 感觉燃尽了，要不暴力然后回去写T2？ 
//11:16 T4这么简单？贪心？我觉得会超时，测一下最后一个大样例 
//11:21 不是，我怎么感觉不会超时呢 
//11:22 不是，真不怎么会超啊，我卡卡常 
//11:26 大样例5的时间卡不过去，算了，看命吧，其他的都没超时，还都过了:) 
//11:27 回头写T2 
//11:44 怎么感觉肝不出来了。。
//11:47 算了认命了 
