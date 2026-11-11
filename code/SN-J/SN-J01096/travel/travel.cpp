#include<iostream>
using namespace std;
int main(){
	int c1,c2;
	string x,y;
	int m,n;
	cin >> c1 >> m >> x >> c2 >> n >> y;
	if(c1==c2){
			cout << "1";
			if(m==n){
				cout << "1";
				if(x='A'){
					if(y='B'){
						cout << "11";
					}else{
						cout << "00";
					}
				}else if(x='B'){
						if(y='A'){
						cout << "11";
					}else if(y='C'){
						cout << "11";
					}else{
						cout << "00";
					}
			}else if(x='C'){
				if(y='B'){
					cout << "11";
				}else{
					cout << "00";
				}
			}else if(x='D'){
				if(y='D'){
					cout << "11";
				}else{
					cout << "00";
				}
			}else if(x='D'){
				if(y='D'){
					cout << "11";
				}
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
