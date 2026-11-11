#include <bits/stdc++.h> 
using namespace std;
string pa;
string pb;
char wa;
char wb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a==c) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	
	for (int i=0;i<=2;i++){
		if (i<=1){
			pa+=b[i];
			pb+=d[i];
		}
		else{
			wa+=b[i];
			wb+=d[i];
		}
	}
	
	
	if (pa==pb) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	if ((wa<='C'&&wb<='C')||(wa>'C'&&wb>'C')) cout << "1";
	else{
		cout << "00";
		return 0;
	} 
	if (wa<='C'&&wb<='C'){
		if (wa-wb==1||wb-wa==1) cout << "1";
		else cout << "0";
	}
	if (wa>'C'&&wb>'C'){
		if (wa-wb==2||wb-wa==2) cout << "1";
		else cout << "0";
	}
	
	return 0;
}
