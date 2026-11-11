#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;

bool car(int c1 , int c2){
	return c1 == c2;
}

bool lin(string s1, string s2){
	char l11 = s1[0];char l12 = s1[0];
	char l21 = s2[0];char l22 = s1[0];
	return (l11 == l21) && (l12 == l22);
}

bool ce(string s1 , string s2){
	char l1 = s1[2]; char l2 = s2[2];
	if(l1 == 'A' || l1 == 'B' || l1 == 'C'){
		if(l2 == 'A' || l2 == 'B' || l2 == 'C'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1 == 'D' || l1 == 'F'){
		if(l2 == 'D' || l2 == 'F'){
			return true;
		}
		else{
			return false;
		}
	}
}

bool ner(string s1 , string s2){
	char l1 = s1[2]; char l2 = s2[2];
	if(l1 == 'A'){
		if(l2 == 'B'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1 == 'B'){
		if(l2 == 'C' || l2 == 'A'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1 == 'C'){
		if(l2 == 'B'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1 == 'D'){
		if(l2 == 'F'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1 == 'F'){
		if(l2 == 'D'){
			return true;
		}
		else{
			return false;
		}
	}
}

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(car(c1,c2)){
		cout << 1;
		if(lin(s1,s2)){
		cout << 1;
			if(ce(s1,s2)){
				cout << 1;
				if(ner(s1,s2)){
					cout << 1;
				} else{
					cout << '0';
				}
			} else {
				cout << '00';
				}	
		} else {
			cout << '000';
		}
	} else {
		cout << '0000';
	}
	
		
	return 0;
	
}
