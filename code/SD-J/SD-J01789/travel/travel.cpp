#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a , b;
	string s1 , s2;
	cin >> a >> s1 >> b >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	if(a == b){
		cout << "1";
		if(s1[1] == s2[1] && s1[2] == s2[2]){
			cout << "1";
			if(s1[3] >= 'A' && s1[3] <= 'C' && s2[3] >= 'A' && s2[3] <= 'C'){
				cout << "1";
				if((s1[3] == 'A' && s2[3] == 'C')||(s2[3] == 'A'&&s1[3] == 'C')){
					cout << "0";
				}else{
					cout << "1";
				}
			}else if(s1[3] >= 'D' && s1[3] <= 'F' && s2[3] >= 'D'&& s2[3] <= 'F'){
				cout << "11"; 
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
	    cout << "0000";
		return 0;	
	}
	return 0;
}
