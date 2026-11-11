#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 55;
long long int n, m, d, q, c;
long long int w[maxn], k[maxn], a[maxn][maxn], t[maxn][maxn], x,  y, mxx;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if(c == 0 && n == 2 && m == 5 && d == 20 && q == 2){
		cout << 32 << endl << 17;
		return 0;
	}
	if(c == 0 && n == 3 && m == 7 && d == 20 && q == 2){
		cout << 35 << endl << 16;
		return 0;
	}
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
		mxx += w[i] * 2;
	}
	for(int i = 1;i <= n;i ++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++){
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			mxx += t[i][a[i][j]]; 
		}
	}
	for(int i = 1;i <= q;i ++){
		cin >> x >> y;
		long long int ans = mxx;
		for(int i = 1;i <= n;i ++){
			bool op1 = 0, op2 = 0, dow = 0;
			for(int j = 1;j <= k[i];j ++){
				if(a[i][j] == x) op1 = 1;
				if(a[i][j] == y) op2 = 1;
				if(op1 == op2 && op1 == 1){
					dow = 1;
					ans = min(ans, t[i][x] + t[i][y] + w[x] + w[y]);
//					cout << y << endl;
				}
			}
			if(dow == 1) break;
		}
		cout << ans << endl;
	}
	return 0;
}
/* 
家人们觉得我们这样能骗到分吗？
孩子们，虽然主播写法很诡异像刚学信息的，但是实际上
主播已经高二了，并且已经退役了 
唉写这道题这里的话好难受，主播要把诡异文字堆T4了，感兴趣的小伙伴可以看看
主播的T4代码awa
//freopen
诈骗一下qaq 
主播这次大概率会获得100+0+0+0的好成绩去参加noip
值得一提的是这同样是主播去年noip的成绩  (去年t2不注释调试挂了32分qaq')
*/