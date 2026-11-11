#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[10000000];
int ans[10000000];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	string desk = "";
	for(int i = 1; i <= n; i ++){
		desk = "";
		for(int j = i; j <= n; j ++){
			if(desk.find(a[j]) != -1){
				desk.erase(desk.find(a[j]), desk.length() - 1);
			}
			desk = desk + a[j] + " ";
		}
		if(desk[0] == ' '){
			desk.erase(0, 1);
		}
		for(int j = 1; j <= n; j ++){
			char ch = char('0' + j);
			if(desk.find(ch) != -1){
				ans[j] ++;
			}
		}
	}
	
	for(int i = 1; i <= n; i ++){
		if(ans[i] == 0){
			continue;
		}
		cout << ans[i] << " ";
	}
	return 0;
} 
