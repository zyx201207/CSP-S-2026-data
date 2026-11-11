include <bits/c++.h>
using namespace std;
int main(){
	string c1
	string c2
	string s1
	string s2
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		if (s1[0] == s2[0] and s1[1] == s2[1]){
			cout << 1;	
			cout << 1;
			if (s1[2]-1 == s2[2] or s1[2]+1 == s2[2]){
				cout << 1;
			}
		}
		else{
			cout << 0;
			cout << 0;
			cout << 0;
		}
	}
	else{
		cout << 0;    
		cout << 0;
		cout << 0;
		cout << 0;
	}
		freclose("travel.in");
		freclose("travel.out");
	return 0;
}                             
