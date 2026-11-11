#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c10,c20;
	string s10,s20;
	cin >> c10 >> s10 >> c20 >> s20;
	if(c10!=c20) cout << "0000";
	else {
		cout << 1;
		if(s10[0]!=s20[0] or s10[1]!=s20[1]){
			cout << "000";
		} else{
			cout << 1;
			char ccc1=s10[2];
			char ccc2=s20[2];
			if((ccc1=='A' and ((ccc2=='D') or (ccc2=='F'))) or (ccc1=='B' and ((ccc2=='D') or (ccc2=='F'))) or (ccc1=='C' and ((ccc2=='D') or (ccc2=='F'))) or (ccc1=='D' and ccc2!='F') or (ccc1=='F' and ccc2!='D')){
				cout << "00";
			}  else {
				cout <<1;
				if((ccc1=='A' and ccc2!='B') or (ccc1=='B' and (ccc2!='A' and ccc2!='C')) or (ccc1=='C' and ccc2!='B') or (ccc1=='D' and ccc2!='F') or (ccc1=='F' and ccc2!='D')){
					cout << "0";
				} else{
					cout << 1;
				}
			}
		}
	} 
	
	return 0;
}
