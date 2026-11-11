#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool check1 (string s1,string s2){
	string ss1,ss2;
	for (int i=0;i<2;i++){
		ss1=ss1+s1[i];
		ss2=ss2+s2[i];
	}
	return (ss1==ss2)?true:false;
}

bool check2 (string s1,string s2){
	char ss1=s1[2],ss2=s2[2];
	if ((ss1 <= 'C' && ss2 <='C') || (ss1>='E' && ss2>='E')){
		return true;
	}
	else{
		return false;
	}
}

bool check3 (string s1,string s2){
	char ss1=s1[2],ss2=s2[2];
	if (ss1+1==ss2 || ss2+1==ss1) return true;
	else return false;
}

int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1!=c2){
		cout << "0000";
	}
	else{
		cout << "1";
		if (check1(s1,s2)){
			cout << "1";
			if (check2(s1,s2)){
				cout << "1";
				if (check3(s1,s2)){
					cout << "1";
				}
				else{
					cout << "0";
				}
				
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	return 0;
}
