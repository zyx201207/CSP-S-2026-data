#include<bits/stdc++.h>
using namespace std;
bool Aside(char side){
	return ('A' <= side && side <='C');
}
bool Dside(char side){
	return ('D' <= side && side <='F');
}
bool isSameSide(char side1,char side2){
	return (Aside(side1) && Aside(side2)) || (Dside(side1) && Dside(side2));
}
bool isNearBy(char side1,char side2){
	if(!isSameSide(side1,side2)) return false;
	if(Aside(side1)){
		return (abs(side1-side2) == 1);
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool q1 = (c1 == c2);
	bool q2 = q1&&(s1[0] == s2[0] && s1[1] == s2[1]);
	bool q3 = q2 && isSameSide(s1[2],s2[2]);
	bool q4 = q3 && isNearBy(s1[2],s2[2]);
	cout << q1 << q2 << q3 << q4;
	return 0;
} 
