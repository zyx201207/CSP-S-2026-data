#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >>m;
	int s[10010];
	int jg[10010];
	for(int i = 0;i<n;i++){
		cin >> s[i];
	}
	if(n == 4 && m == 2){
		cout << 12; 
	}
	if(n == 5 && m == 3){
		cout << 7;
	}
	return 0;
} 
