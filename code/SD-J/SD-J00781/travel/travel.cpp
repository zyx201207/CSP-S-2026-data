#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2){
		cout << "1";
		string p1=s1.substr(0,2);
		string p2=s2.substr(0,2);
		char l1=s1[2], l2=s2[2];
		if (p1==p2){
			cout << "1";
			if ((l1<='C'&&l2<='C')||
			(l1>='D'&&l2>='D')) 
			{
				cout << "1";
				if (abs(l1-l2)==1||
					(l1=='D'&&l2=='F')||
					(l2=='D'&&l1=='F')){
					cout << "1\n";
					return 0;
				}
				else {
					cout << "0\n";
					return 0;
				}
			}
			else {
				cout << "00\n";
				return 0;
			}
		}
		else {
			cout << "000\n";
			return 0;
		}
	}
	else {
		cout << "0000\n";
		return 0;
	}
}
