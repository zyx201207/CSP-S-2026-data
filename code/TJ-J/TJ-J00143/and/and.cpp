#include <iostream>
using namespace std;
int n, m, y, q;
int z = 0;
int main{
	cin>>n;
	cin>>q;
	int mach[n];
	for(int i, i = 0, i <= n - 1, i++){
		cin>>m;
		mach[i] = m;
	}
	for(int j, j = 0, j <= n, j++){
		for(int x, x = 1, x <= j, x++){
			y = mach[j] and mach[x];
			if(y >= z){
				z = y;
			}
		}
	}
	cout<<z;
}
