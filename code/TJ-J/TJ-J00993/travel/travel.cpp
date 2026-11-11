#include<bits/stdc++.h>
using namespace std;

int cr, cx;
string sr, sx;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cr >> sr >> cx >> sx;
	
	if(cr == cx){
		cout << "1";
	}else {
		cout << "0";
		cout << "0";
		cout << "0";
		cout << "0";
		return 0;
	}
	if(sr[0] == sx[0] && sr[1] == sx[1]){
		cout << "1";
	}else {
		cout << "0";
		cout << "0";
		cout << "0";
		return 0;
	}
	if(sr[2] - 'A' <= 2 && sx[2] - 'A' <= 2 || 'F' - sr[2] == 2 && 'F' - sx[2] == 0 || 'F' - sr[2] == 0 && 'F' - sx[2] == 2){
		cout << "1";
	}else {
		cout << "0";
		cout << "0";
		return 0;
	}
	if((sr[2] - sx[2] == 1 || sr[2] - sx[2] == -1) && (sr[2] - 'A' <= 2 && sx[2] - 'A' <= 2)  || 'F' - sr[2] == 2 && 'F' - sx[2] == 0 || 'F' - sr[2] == 0 && 'F' - sx[2] == 2){
		cout << "1";
	}else {
		cout << "0";
	}
	
	
	return 0;
}
