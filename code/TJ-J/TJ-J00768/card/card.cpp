#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
const int M = 1e5 + 10;
int cards[N] , have[M];
int nnn[N];

int check(int num , int cnt){
	for (int i = 0; i <= cnt; i ++){
		if (nnn[i] == num) return i;
	}
	return -1;
}

signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	//如果需要调试请注释
	//如果需要提交请删掉注释 
	
	int n , m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> cards[i];
	}
	for (int i = 1; i <= n; i ++){ //第i轮游戏（从第i张牌开始） 
		int cnt = 0;
		for (int j = i; j <= n; j ++){ //第i轮游戏即将打出第j张牌 
			int cccc = check(cards[j] , cnt);
			if (cccc == -1){
				nnn[cnt] = cards[j];
				cnt ++;
				continue;
			}
			
			cnt = cccc + 1;
		}
		//第i轮游戏结束 进入结算时间（做统计）
		for (int j = 0; j < cnt; j ++) have[nnn[j]] ++;
		cout << endl;
	}
	for (int i = 1; i <= m; i ++) cout << have[i] << " ";
	//完结撒花 
	return 0;
}
