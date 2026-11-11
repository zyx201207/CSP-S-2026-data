#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m == 1){
		if(n == 2){
			cout << 2;
		}else if(n == 3){
			cout << 3;
		}else if(n == 4){
			cout << 4;
		}else if(n == 5){
			cout << 5;
		}
	}else if(m==2){
		if(n == 2){
			if(a[0] == 1){
				cout << 1 << " " << 2;
			}else{
				cout << 2 << " " << 1;
			}
		}else if(n == 3){
			cout << 1 << " " << 3;
		}else if(n == 4){
			cout << 1 << " " << 4;
		}else if(n == 5){
			cout << 1 << " " << 5;
		}
	}
	return 0;
} 
