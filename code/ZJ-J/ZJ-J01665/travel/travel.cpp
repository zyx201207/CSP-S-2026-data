#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string fir = "DF",nex = "ABC";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000" << endl;
	}
	else{
		string x1 = s1.substr(0,2),x2 = s2.substr(0,2);
		if(x1 != x2){
			cout << "1000" << endl;
		}
		else{
			bool f = 1;
			for(int i = 0;i < fir.size();i++){
				for(int j = 0;j < nex.size();j++){
					if((s1[2] == fir[i] && s2[2] == nex[j]) || (s2[2] == fir[i] && s1[2] == nex[j])){
						f = 0;
						break;
					}
				}
			}
			if(f == 0){
				cout << "1100" << endl;
			}
			else{
				int x = s1[2] - 'A',y = s2[2] - 'A';
				if(abs(x-y) > 1){
					cout << "1110" << endl;
				}
				else{
					cout << "1111" << endl;
				}
			}
		}
	}
	return 0;
}