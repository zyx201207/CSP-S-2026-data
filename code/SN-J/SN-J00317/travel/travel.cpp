#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int m = 1;
	if(c1 == c2){
		cout << 1;
		m = 1;
	}else{
		cout << 0;
		m = 0;
		m = 0;
		m = 0;
	}
	int a[5];
	int b[5];
	a[0] = s1[0];
	a[1] = s1[1];
	b[0] = s2[0];
	b[1] = s2[1];
	if(a[0] == b[0]&&a[1] == b[1]&&m!=0){
		cout << 1;
		m = 1;
	}else{
		cout << 0;
		m = 0;
		m = 0;
		m = 0;
	}
	if(((s1[2] == 'A'&&s2[2] == 'B')||(s1[2] == 'A'&&s2[2] == 'C')||(s1[2] == 'B'&&s2[2] == 'C')||(s1[2] == 'D'&&s2[2] == 'F')||(s1[2] == 'B'&&s2[2] == 'A')||(s1[2] == 'C'&&s2[2] == 'A')||(s1[2] == 'C'&&s2[2] == 'B')||(s1[2] == 'F'&&s2[2] == 'D'))&&m!=0&&s1[2] != s2[2]){
		cout << 1;
	}else{
		cout << 0;
		m = 0;
		m = 0;
		m = 0;
	}
	if(((s1[2] == 'A'&&s2[2] == 'B')||(s1[2] == 'B'&&s2[2] == 'C')||(s1[2] == 'D'&&s2[2] == 'F')||(s1[2] == 'B'&&s2[2] == 'A')||(s1[2] == 'C'&&s2[2] == 'B')||(s1[2] == 'F'&&s2[2] == 'D'))&&m!=0&&s1[2] != s2[2]){
		cout << 1;
		m = 1;
	}else{
		cout << 0;
		m = 0;
	}
	
	return 0;
}
