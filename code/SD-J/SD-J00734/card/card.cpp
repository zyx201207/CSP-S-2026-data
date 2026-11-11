#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct node{
	int lt;
	bool operator < (const node y) const{
		return lt < y.lt;
	}
};
int n , m , a[N] , lst[N] , top , ans[2][N] , flag[N] , res , pre[N] , sum[2][N];
bool book[N];
priority_queue<node> qe;
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i++){
		lst[i] = flag[a[i]];
		flag[a[i]] = i;
	}
	for(int i = n ; i >= 1 ; i--){
		while(qe.size() && qe.top().lt >= i) qe.pop();
		qe.push((node){lst[i]});
		pre[i] = qe.top().lt;
	}
	for(int i = 1 ; i <= n ; i++) cout << pre[i] << " "; cout << endl;
	for(int i = 1 ; i <= n ; i++){
		book[i] = !book[pre[i]];
		sum[!book[i]][i] = sum[!book[i]][pre[i]];
		sum[book[i]][i] = sum[book[i]][pre[i]] + i - pre[i];
		ans[book[i]][a[i]] = sum[book[i]][i];
	}
	for(int i = 1 ; i <= n ; i++){
		cout << book[i] << " " << sum[0][i] << " " << sum[1][i] << endl;
	}
	for(int i = 1 ; i <= m ; i++) cout << ans[0][i] + ans[1][i] << " ";
	return 0;
}
