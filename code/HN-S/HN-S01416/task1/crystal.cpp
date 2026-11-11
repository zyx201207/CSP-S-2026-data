#include<bits/stdc++.h>
using namespace std;

int x[500001];
int main(){
	int n, m, Middle, T;
	cin >> n >> m;
	for(int i = 1;i < n;i++){
		cin >> x[n];
	}
	T = 1;
	Middle = x[n / 2 + 1];
	for(int i = 1;m > 0;i++){
		if(x[i] < 2 || x[i] == Middle){
			T += 1;
			m = m-(Middle - x[i]);
		}
	}
	cout << T << endl;
	
	return 0;
}
