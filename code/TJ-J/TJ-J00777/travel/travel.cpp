#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a=true;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2){
		cout << 1;
		for (int i=0;i<2;i++){
			if (s1[i]!=s2[i]) a=false;
		}
		if (a){
			cout << 1;
			if ((s1[2]<='C'&&s2[2]<='C') || (s1[2]>'C' &&s2[2]>'C')){
				cout << 1;
				int sc=(int)s1[2]-(int)s2[2];
				if (sc==1 || sc==-1){
					cout << 1;
				}else cout << 0;
			}else{
				cout << "00";
			}
		}else {
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
