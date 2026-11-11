#include<bits/stdc++.h>
using namespace std;
int a , b;
string x , y , n , m;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> x >> b >> y;
	if(a == b){
		cout << 1;
	}else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	n += x[0];
	n += x[1];
	m += y[0];
	m += y[1];
	if(n == m){
		cout << 1;
	}else{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	bool p = false;
	if((x[2] >= 'A' && x[2] <= 'C' && y[2] >= 'A' && y[2] <= 'C') || (x[2] >= 'D' && x[2] <= 'F' && y[2] >= 'D' && y[2] <= 'F')){
		cout << 1;
		p = true;
	}else{
		cout << 0;
	}
	if(!p){
		cout << 0;
	}else{
		if(x[2] == 'B' || y[2] == 'B' || x[2] >= 'D' || y[2] >= 'D'){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}
