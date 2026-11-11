#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		a = 1;
		if (s1[1] == s2[1] && s1[0] == s2[0]){
			b = 1;
			if (s1[2] == 'D' || s2[2] == 'D'){
				if (s1[2] == 'F' || s2[2] == 'F'){
					c = 1;
				}
			}
			else{
				c = 1;
			}
			if (c == 1){
				if (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1){
					d = 1;
				}
			}
		}
	}
	cout << a << b << c << d;
} 
