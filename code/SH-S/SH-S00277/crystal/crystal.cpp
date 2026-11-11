/*
印象中有一种和蛇相关的算法
具体表现为：如果一条“蛇”不符合规则，那么蛇的尾要向前移一格，再去判断蛇的头能否在合法情况下向前走
所以，这个题除了基本的递归之外，还要考虑这种思想
*/ 

#include<bits/stdc++.h>
#define N 500009
using namespace std;
typedef long long ll;
int n;
ll ans, m, a[N], f[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	
	sort(a+1, a+n+1); //预处理 
	
	int head = 1, tail = 1;
	while(head <= n){
		ans = max(ans, head - tail + 1ll); //更新ans 
		head++; //蛇头向前移 
		f[head] = f[head-1] + 1ll * (head - tail) * (a[head] - a[head-1]); //递归方程
		
		while(f[head] > m){ //蛇尾向前移 
			f[head] -= (a[head] - a[tail]);
			tail++;
		}
	}
	
	cout << ans;
	return 0;
}
