#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>s1 >> c2 >>  s2;
	if(c1 == c2){
		cout << "1";
		if(s1[0] == s2[0] &&  s1[1] ==  s2[1]){
			cout << "1";
			if((s1[2]>='D' && s2[2] >= 'D') || (s1[2] <= 'C' && s2[2] <= 'C')){
				cout << "1";
				int cha = abs((int)s1[2]  -  (int)s2[2]);
				if(cha == 1){
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
	else{
		cout << "0000";
	}
	return 0;
}
