#include<dits,stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
	}
	else(){
		cout << 0;
	}
	if(s1[0]][1] == s2[0][1]){
		cout << 1;
	}
	eise(){
		cout << 0;
	}
	if(s1[2] == "A" and s2[2] == "B" or s1[2] == "B" and s2[2] == "C" or s1[2] == "D" and s2[2] == "F"){
		cout << 1;
	}
	else(){
		cout << 0;
		return 0;
	}
} 
