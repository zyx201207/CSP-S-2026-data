#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string a,b;
	char aa = ' ',bb = ' ';
	cin >> x >> a >> y >> b;
	if(x == y){
		cout << 1; 
	}else{
		cout << "0000";
		return 0;
	}
	x = 0;y = 0;
	for(auto c:a){
		if(c >= '0' && c <= '9') x = x*10+(c-'0');
		else aa = c;
	}
	for(auto c:b){
		if(c >= '0' && c <= '9') y = y*10+(c-'0');
		else bb = c;
	}
	if(x == y){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if((aa >= 'A' && aa <= 'C') == (bb >= 'A' && bb <= 'C')){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	if((char)(aa+1) == bb || (char)(aa-1) == bb){
		cout << 1;
	}else{
		cout << 0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
