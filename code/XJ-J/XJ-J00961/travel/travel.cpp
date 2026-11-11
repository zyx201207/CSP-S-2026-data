#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trave.in","r",stdin);
	freopen("trave.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char k1 = s1[2];
	char k2 = s2[2];
	int j1 = int(k1);
	int j2 = int(k2);
	if(c1 == c2){
		if(s1[0]*10 + s1[1] == s2[0]*10 + s2[1]){
			if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')){
				if(s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1){
					cout<< "1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0 ;
	}
