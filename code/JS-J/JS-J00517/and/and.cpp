#include<bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
int a[10000];

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int tmp = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(a[i] and a[j] > tmp){
				tmp = a[i] and a[j];
			}
		}
	}
	cout << tmp;
	return 0;
}
