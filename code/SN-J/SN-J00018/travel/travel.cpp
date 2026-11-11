#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> x >> y;
	if(a == x) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	
	for(int i = 0;i < 2;i++){
		if(b[i] != y[i]){
			cout << "000";
			return 0;
		}
	}
	cout << 1;
	
	char t = b[b.size() - 1],r = y[y.size() - 1];
	if(t == 'A' || t == 'B' || t == 'C'){
		if(r == 'A' || r == 'B' || r == 'C') cout << 1;
		else{
			cout << "00";
			return 0;
		}
	}
	if(t == 'D' || t == 'F'){
		if(r == 'D' || r == 'F') cout << 1;
		else{
			cout << "00";
			return 0;
		}
	}
	
	if(t == 'A'){
		if(r == 'B') cout << 1;
		else cout << 0;
	}
	else if(t == 'B'){
		if(r == 'A' || r == 'C') cout << 1;
		else cout << 0;
	}
	else if(t == 'C'){
		if(r == 'B') cout << 1;
		else cout << 0;
	}
	else if(t == 'D'){
		if(r == 'F') cout << 1;
		else cout << 0;
	}
	else if(t == 'F'){
		if(r == 'D') cout << 1;
		else cout << 0;
	}
	return 0;
}

