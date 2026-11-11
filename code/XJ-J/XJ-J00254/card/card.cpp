#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2,num;
	cin >> c1 >> s1 >> c2 >> s2;
	int n,m,a[10011];
	int sum[10011];
	int num = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		for(int j = 1; j <= m; j++){
			sum[i] == a[i] << a[j];
			if (sum[i] >= sum[i - 1]){
				num = sum[i];
			}
		}
	}
	cout << num;
	return 0;
}

