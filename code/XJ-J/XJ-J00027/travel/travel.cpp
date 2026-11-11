#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2,c1,c2;
char ch;
bool bet(){
	if((c1 == "A" || c1 == "B" || c1 == "C") && (c2 == "D" || c2 == "E"))return 0;
	if((c2 == "A" || c2 == "B" || c2 == "C") && (c1 == "D" || c1 == "E"))return 0;
	return 1;
}
bool bet2(){
	if((c1 == "A" || c1 == "B" || c1 == "C") && (c2 == "D" || c2 == "E"))return 0;
	if((c2 == "A" || c2 == "B" || c2 == "C") && (c1 == "D" || c1 == "E"))return 0;
	if(abs(int(c1[0]-c2[0])) == 1)return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1;
	cin >> ch;b1 += ch;cin >> ch;b1 += ch;cin >> ch;c1 += ch;
	cin >> a2;
	cin >> ch;b2 += ch;cin >> ch;b2 += ch;cin >> ch;c2 += ch;
	cout << (a1 == a2);
	cout << (a1 == a2 && b1 == b2);
	cout << (a1 == a2 && b1 == b2 && bet());
	cout << (a1 == a2 && b1 == b2 && bet() && bet2());
	return 0;
} 
