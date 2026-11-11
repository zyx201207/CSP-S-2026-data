#include <bits/stdc++.h>
using namespace std;
int n,m;
int now[30000];
int pai[30000];
int a;
int main(){
	// no matter , good luck!
	//^v^
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> pai[i];
	}
	for(int i = 1; i <= n; i++){
		now[i] = pai[i];
		for(int j =1 ; j<=i;j++){
			if(now[j]==pai[i]){
				now[j] = 0;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(pai[i] == i && a <= m){
			cout << i;
			a++;
		}
	}
	
	return 0;
	
}
