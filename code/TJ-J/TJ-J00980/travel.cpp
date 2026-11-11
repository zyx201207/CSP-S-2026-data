#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a1,a2;
	cin >> a1 >> a2;
	string b1,b2;
	cin >> b1 >> b2;
	
	
	if(a1 == b1) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	
	if(a2[0] == b2[0] && a2[1] == b2[1]){
		cout << 1;
	}
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	
	if((a2[2] == 'A' || a2[2] == 'B' ||a2[2] == 'C')&&(b2[2]=='D' || b2[2] == 'F')){
		cout << 0 << 0;
		return 0;
	}
	else if((b2[2] == 'A' || b2[2] == 'B' ||b2[2] == 'C')&&(a2[2]=='D' || a2[2] == 'F')){
		cout << 0 << 0;
		return 0;
	}
	else cout << 1;
	
	if(char(a2[2]+1) == char(b2[2]) || char(a2[2]-1) == char(b2[2])){
		cout << 1;
	}
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
