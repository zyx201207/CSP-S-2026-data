#include <iostream>
using namespace std;
int n, m, zong, dzong, jie;
char zi;
int main{
	cin>>n;
	int ch[n]
	for(int i, i = 0, i <= n - 1, i++){
		cin>>m;
		cin>>zi;
		ch[i] = m
	}
	for(int y, y = 0, y <= n - 1, y++){
		dzong += ch[y]	
	}
	if(n % 2 == 1){
		for(int j, j = 0, j <= n / 2 - 1, j++){
		zong += ch[j]	
		}
		if(dzong - ch[n / 2 + 1] == zong * 2){
			jie = dzong - ch[n / 2 + 1] - zong;
		}
		else{
			for(int dao, dao = n, dao > n / 2 + 1, dao--){
				jie += ch[dao]
			}
		}
		cout<<jie;
	}
	else{
		for(int w, w = 0, w <= n / 2, w++){
		jie += ch[w]	
		}
		cout<<jie;
	}
} 
