#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,s1lie,s2lie;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
	}
	else{
		cout << "0000";
		return 0;
	}
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]){
		cout << "1";
	}
	else{
		cout << "000";
		return 0;
	}
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]){
		s1lie = s1[2];
		s2lie = s2[2];
		if((s1lie == "A" || s1lie == "B" || s1lie == "C") && (s2lie == "A" || s2lie == "B" || s2lie == "C") ||(s1lie == "D" || s1lie == "F") && (s2lie == "D" || s2lie == "F") ){
			cout << "1"; 
			if(((s1lie == "A" && s2lie == "B") || (s1lie == "B" && s2lie == "C") || (s1lie == "D" && s2lie == "F"))  ||  ((s2lie == "A" && s1lie == "B") ||  (s2lie == "B" && s1lie == "C") || (s2lie == "D" && s1lie == "F"))){
				cout << "1";	
			}
			else{
				cout << "0";
			}
		}
		else{
			cout << "00";
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
