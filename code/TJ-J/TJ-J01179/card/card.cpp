#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 * 5 + 5;
const int M = 1e3 * 5 + 5;
int n, m;
int a[N], nw[N], num[M];
//num[i] i在n局中有多少次结束时留有点数为 i 的牌
void gm(int x){
	int cnt = 0;
	for(int i = x; i <= n; i++){
		int k = a[i], sf = 0;
		for(int j = 1; j <= cnt; j++){
			if(nw[j] == k){
				sf = 1;
				nw[j] = k;
			}
			else{
				if(sf){
					nw[j] = 0;
					cnt--;
				}
			}
		}
		if(!sf){
			cnt++;
			nw[cnt] = k;
		}
	}
	for(int i = 1; i <= cnt; i++){
		num[nw[i]]++;
	}
	return ;
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		gm(i);
	}
	for(int i = 1; i <= m; i++){
		cout << num[i] << " ";
	}
	return 0;
}
