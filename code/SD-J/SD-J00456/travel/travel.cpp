#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in", "r",stdin);
	freopen("travel.out","w",stdout);
	
	
	string cx,sx,cr,sr;
	cin >> cx >> sx >> cr >> sr;
	bool c = false , s = false , z = false;
	if (cx == cr){
		cout << 1;
		c = true;
	}else{
		cout << 0;
	}
	string tmpsr,tmpsx;
	
	
	
	for (ll i = 0;i <= 1; i ++){
		tmpsr += sr[i];
		tmpsx += sx[i];
	}
	if (tmpsr == tmpsx && c){
		cout << 1;
		s = true;
	}else{
		cout << 0;
	}
	
	
	
	bool a = false;
	bool b = false;
	if ((sr[2] == 'A' || sr[2] == 'B'|| sr[2] == 'C') && c && s){
    	a = true;
	}
	if ((sx[2] == 'A'||sx[2] == 'B'|| sx[2] == 'C') && c && s){
		b = true;	
	}
	if ( ( a && b ) || ( !a && !b) && c && s){
		cout << 1;
		z = true;
	}else{
		cout << 0;
	}
	
	
	
	if (!a && !b&& c && s && z){
		cout << 1;
	}else if((sr[2] + 1 == sx[2] || sx[2] + 1 == sr[2]) && z&& c && s){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
