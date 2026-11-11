#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string a;
int main(){
	freopen("travel.in", "r",stdin);
	freopen("travel.out", "w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0]==c2[0]&&c1[1]==c2[1]){
		a = "1";
		if (s1[0]==s2[0]&&s1[1]==s2[1]){
			a += "1";
			if ((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				a += "1";
				if (s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					a += "1";
				}
				else{
					a += "0";
				}
			}
			else{
				a += "00";
			}
		}
		else{
			a += "000";
		}
	}
	else{
		a = "0000";
	}
	cout << a[0] << a[1] << a[2] << a[3];
	return 0;
}
