#include <bits/stdc++.h>
#define ll long long
#define IO freopen("card.in","r",stdin),freopen("card.out","w",stdout)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pqu priority_queue

#define lowbit(x) ((x) & (-x))

using namespace std;

const int MAXN = 500010;
int n,m;
int a[MAXN],ans[MAXN];
int ti[MAXN];
bool ins[MAXN];

void solveA(){
	for(int i = 1;i <= n;i ++){
		ans[a[i]] = i;
	}
	for(int i = 1;i <= m;i ++){
		cout << ans[i] << ' ';
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	IO;
	cin >> n >> m;
	bool isA = 1;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] < a[i - 1]) isA = 0;
	}
	
	if(isA){
		solveA();
		return 0;
	}
	
	for(int i = 1;i <= n;i ++){
		stack <int> stk;
		memset(ins,0,sizeof ins);
		for(int j = i;j <= n;j ++){
			if(ins[a[j]]){
				while(!stk.empty() && stk.top() != a[j]){
					ins[stk.top()] = 0;
					stk.pop();
				}
			}
			else{
				stk.push(a[j]);
				ins[a[j]] = 1;
			}
		}
		while(!stk.empty()){
			ans[stk.top()] ++;
			stk.pop();
		}
	}
	for(int i = 1;i <= m;i ++){
		cout << ans[i] << ' ';
	}
	return 0;
}

//start time: 16:30
//end time: 20:00

//CSP-J 2026 JX
//do not forget to add freopen!

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

//diff /home/noi/CSP-J00594/card/card.out /home/noi/CSP-J00594/card/card3.ans

/*
 * shenle,wozenmebuhui
 * xiebuchulvti
 * daobile
 * 100+100+100+52=352?
 * luogu xiaotian_qwq is fw
*/
