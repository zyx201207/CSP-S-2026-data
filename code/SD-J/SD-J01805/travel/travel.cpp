#include<bits/stdc++.h>
using namespace std;
string car1,car2,seat1,seat2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> car1 >> seat1 >> car2 >> seat2;
	bool awa = true;
	for (int i = 0;i <= 1;i++){
		if (car1[i] != car2[i]){
			awa = false;
		}
	}
	if (!awa){
		cout << "0000" << endl;
		return 0;
	}
	
	for (int i = 0;i <= 1;i++){
		if (seat1[i] != seat2[i]){
			awa = false;
		}
	}
	if (!awa){
		cout << "1000" << endl;
		return 0;
	}
	
	int a = 0,b = 0;
	if (seat1[2] =='A' || seat1[2] == 'B' || seat1[2] == 'C'){
		a = 1;
	}
	if (seat2[2] =='A' || seat2[2] == 'B' || seat2[2] == 'C'){
		b = 1;
	}
	if (a != b){
		cout << "1100" << endl;
		return 0;
	}
	
	awa = false;
	if (seat1[2] == 'A' && seat2[2] == 'B'){
		awa = true;
	} else if (seat2[2] == 'A' && seat1[2] == 'B'){
		awa = true;
	} else if (seat1[2] == 'B' && seat2[2] == 'C'){
		awa = true;
	} else if (seat2[2] == 'B' && seat1[2] == 'C'){
		awa = true;
	} else if (seat1[2] == 'D' && seat2[2] == 'F'){
		awa = true;
	} else if (seat1[2] == 'F' && seat2[2] == 'D'){
		awa = true;
	}
	if (awa){
		cout << "1111" << endl;
	} else {
		cout << "1110" << endl;
	}
	return 0;
} 
