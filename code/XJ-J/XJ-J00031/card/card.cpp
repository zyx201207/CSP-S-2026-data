#include<bits/stdc++.h> 
using namespace std;
int a[100005],w[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= m;i++){ // --> 总
		int e = 1; // --> 计数器（push and a）
		for (int j = 1;j <= n;j++){ // --> push
			a[e] = w[j]; // --> 从w push a
			e++;
			for (int l = 1;l < e;l++){ // 第k张牌 
				if (w[j] == a[l]){
					e = l;
					for (int o = l;o <= j;o++){
						a[o] = 0;
					} 
				}
			}
		} 
	}
	for (int i = 1;i <= 10005;i++){
		if (a[i] != 0){
			cout << a[i] << " ";
		}
	}
	return 0;
} 
