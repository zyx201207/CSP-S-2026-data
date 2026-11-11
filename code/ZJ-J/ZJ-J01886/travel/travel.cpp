#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int a1 = s1[0]-'0',b1 = s1[1]-'0',d1 = s1[2]-'A';
	int a2 = s2[0]-'0',b2 = s2[1]-'0',d2 = s2[2]-'A';
	if(c1 == c2){
		cout << 1;
		if(a1 == a2 && b1 == b2){
			cout << 1;
			if((d1<3 && d2<3) || (d1>=3 && d2>=3)){
				cout << 1;
				if(abs(d1-d2) == 1)	cout << 1;
				else cout << 0;
			}else cout << "00";
			
		}else cout << "000";
	}else	cout << "0000";
	return 0;
}
