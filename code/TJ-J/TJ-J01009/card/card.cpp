#include <bits/stdc++.h>
using namespace std; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int card[n+1];
	for (int i = 1;i <= n;i ++){
		cin >> card[i];
	}
	int k;
	for (int i = 1;i <= n;i ++){
		int desk[n];
		
		for (int j = i;j <= n;j ++){
			k = card[i];
			desk[j] = k;
		}
	}
}
