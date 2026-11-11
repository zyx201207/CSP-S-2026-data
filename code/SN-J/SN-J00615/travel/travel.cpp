#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string x = s1.substr(0,2);
	string y = s2.substr(0,2);
	if(c1 == c2){
		cout<<"1";
		if(x == y){
			cout<<"1";
			if(s1[2] >= 'D' && s1[2] <= 'R'){
				if(s2[2] >= 'D' && s2[2] <= 'F'){
					cout<<"1";
					if(s1[2] != s2[2]) cout<<"1";
					else cout<<"0";
				}
				else cout<<"00";
			}
			else{
				if(s2[2] >= 'A' && s2[2] <= 'C'){
					cout<<"1";
					if((int)s1[2] < (int)s2[2]){
						if((int)s2[2] - (int)s1[2] == 1) cout<<"1";
						else cout<<"0";
					}
					else{
						if((int)s1[2] - (int)s2[2] == 1) cout<<"1";
						else cout<<"0";
					}
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
