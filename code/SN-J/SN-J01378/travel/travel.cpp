#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
bool a1 , a2 , a3 , a4;
int c1,c2,z1,z2;
string s1 , s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	z1 = s1[0]*10+s1[1];
	z2 = s2[0]*10+s2[1];
	if (c1 == c2){
		a1 = true; 
		if (z1 == z2){
			a2 = true;
			if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
				a3 = true;
				if (s1[2]-1 == s2[2]||s1[2]+1 == s2[2]) a4 = true;
			} else if (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'){
				a3 = true;
				if (s1[2]-1 == s2[2]||s1[2]+1 == s2[2]) a4 = true;
			}
		}
	}
	cout << a1 << a2 << a3 << a4 << endl;
	return 0;
}
