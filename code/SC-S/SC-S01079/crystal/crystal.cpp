#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	//freopen("crystal.in", r, stdin);
	//freopen("crystal.out", w, stdout);
	
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	
	int n, k;
	long long cry[260005] = {0};
	long long m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)cin >> cry[i];
	sort(cry + 1, cry + n + 1);
	
	k = 1;
	for(int i = 2; i <= n; i++){
		m = m - (cry[i] - cry[i - 1]) * (i - 1);
		if(m >= 0)k++;
	}
	cout << k;
	return 0; 
}