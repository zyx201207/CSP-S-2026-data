#include <iostream>
using namespace std;
int n, m, a;
int js = 0;
int main{
	cin<<n, m;
	for(int b, b = 1, b <= m, b++){
		int m_b;
		int biao[n];
		int zhuo[n];
		for(int i, i = 0, i <= line(biao[]) - 1, i++){
			cin<<a;
			biao[i] = a;
		}
		for(int j, j = 0, j <= line(biao[]) - 1, j++){
			zhuo[j] = biao[js];
			js += 1;
			if(js > n){
				js = 0;
			}
			for(int l, l = 0, l <= j, l++){
				if(zhuo[j] == zhuo[l]){
					for(int q, q = 0, q < j, q++){
						append(zhuo[q]);
					}	
				}
			}
			append(biao[0])
		}
	}
}
