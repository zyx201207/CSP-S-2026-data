#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w",stdout);
	string c_1, c_2, v_1, v_2;
	cin >> c_1 >> c_2 >> v_1 >> v_2;
	if(c_1[0] == v_1[0] && c_1[1] == v_1[1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if(c_1[0] == v_1[0] && c_1[1] == v_1[1] && c_2[0] == v_2[0] && c_2[1] == v_2[1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if(c_1[0] == v_1[0] && c_1[1] == v_1[1] && c_2[0] == v_2[0] && c_2[1] == v_2[1]){
		if(c_2[2] >= 'A' && c_2[2] <= 'C' && v_2[2] <= 'C' && v_2[2] >= 'A'){
			cout << 1;
		}
		else if(c_2[2] >= 'D' && c_2[2] <= 'F' && v_2[2] <= 'F' && v_2[2] >= 'D'){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	
	if(c_1[0] == v_1[0] && c_1[1] == v_1[1] && c_2[0] == v_2[0] && c_2[1] == v_2[1]){
		if(c_2[2] >= 'D' && c_2[2] <= 'F' && v_2[2] <= 'F' && v_2[2] >= 'D'){
			cout << 1;
		}
		else if(c_2[2] >= 'A' && c_2[2] <= 'C' && v_2[2] <= 'C' && v_2[2] >= 'A'){
			if(c_2[2] == 'A' && v_2[2] == 'B' || c_2[2] == 'B' && v_2[2] == 'A' || c_2[2] == 'B' && v_2[2] == 'C' || c_2[2] == 'C' && v_2[2] == 'B'){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	
	return 0;
} 
