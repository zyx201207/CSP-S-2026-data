#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10 , N2 = 3e5 + 10;

int n , m , a[N] , vis[N] , cnt[N2];

void solve1(){
	for(int i = 1 ; i <= n ; i++){
		memset(vis , 0 , sizeof vis);
		stack<int> stk;
		for(int j = i ; j <= n ; j++){
			if(!vis[a[j]]){
				stk.push(a[j]);
				vis[a[j]] = true;
			}else{
				while(stk.top() != a[j]){
					int tmp = stk.top();
					vis[tmp] = false;
					stk.pop();	
				}
			}
		}
		while(!stk.empty()){
			cnt[stk.top()]++;
			stk.pop();
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cout << cnt[i] << " ";
	}
}

bool check(){
	bool flag = true;
	for(int i = 2 ; i <= n ; i++){
		if(a[i] < a[i-1]){
			flag = false;
			break;
		}
	}
	return flag;
}

void solve2(){
	int num = 1;
	for(int i = 1 ; i <= n ; i++){
		if(a[i] != a[i+1]){
			cnt[a[i]] = i;
		}
	}
	for(int i = 1 ; i <= m ; i++)
		cout << cnt[i] << " ";
}

int main(){

	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	if(check()){
		solve2();
	}
	else if(n <= 5000){
		solve1();
	}
	
	return 0;
}
