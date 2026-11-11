#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[5*N];
int ans[3*N];
int vis[3*N] = {0};
stack<int> zhan;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			vis[a[j]]++;
			if(vis[a[j]] == 2){
				while(zhan.top() != a[j]){
					vis[zhan.top()]--;
					zhan.pop();
				}
				vis[zhan.top()]--;
				zhan.pop();
			}
			zhan.push(a[j]);
		}
		while(!zhan.empty()){
			vis[zhan.top()]--;
			ans[zhan.top()]++;
			zhan.pop();
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cout << ans[i] << " ";
	}
	return 0;
} 
