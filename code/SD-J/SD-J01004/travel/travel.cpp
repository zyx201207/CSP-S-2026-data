#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool b1=true, b2=true, b3, b4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i=0;i<2;i++){
		if (c1[i]!=c2[i]) b1=false;
	}
	if (b1==false){
		cout << "0000" << endl;
		return 0;
	}
	for (int i=0;i<2;i++){
		if (s1[i]!=s2[i]) b2=false;
	}
	if (b2==false){
		cout << "1000" << endl;
		return 0;
	}
	if ((s1[2]-'A'<=2&&s2[2]-'A'<=2) || (s1[2]-'A'>2&&s2[2]-'A'>2)) b3=true;
	if (b3==false){
		cout << "1100" << endl;
		return 0;
	}
	if (s1[2]-s2[2]==1 || s2[2]-s1[2]==1) b4=true;
	if (b4==false){
		cout << "1110" << endl;
		return 0;
	}
	cout << "1111" << endl;
	return 0;
}
