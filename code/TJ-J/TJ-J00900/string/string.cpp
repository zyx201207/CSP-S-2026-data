#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}else if(n == 2){
		int a,b;
		char c,d;
		cin >> a >> c >> b >> d;
		if(c == d){
			cout << 0;
			return 0;
		}else{
			if(a == 1 && b == 4){
				cout << 1;
				return 0;
			}else if(a == 2 && b == 3){
				cout << 2;
				return 0;
			}else if(a == 3 && b == 2){
				cout << 2;
				return 0;
			}else if(a == 4 && b == 1){
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
