#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	int c1,c2;
	string s1,s2;
	int h1,h2;
	cin >> c1 >> s1 >> c2 >> s2;
	h1=(s1[0]-'0')*10+(s1[1]-'0');
	h2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout << 1;
		if(h1==h2){
			cout << 1;
			if(s1[2]<='C' and s2[2]<='C' or s1[2]>='D' and s2[2]>='D'){
				cout << 1;
				if(abs(s1[2]-s2[2])==1){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	return 0;
}
