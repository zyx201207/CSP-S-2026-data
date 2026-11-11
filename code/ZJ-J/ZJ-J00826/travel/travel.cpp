#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cara,carb;
string seata,seatb;
char near1(char p){
	if(p=='A') return 'B';
	if(p=='B') return 'A';
	if(p=='C') return 'B';
	if(p=='D') return 'F';
	if(p=='F') return 'D';
	return 'Z';
}
char near2(char p){
	if(p=='B') return 'C';
	return 'Z';
}
int main(){
	//freopen
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//code
	cin>>cara>>seata>>carb>>seatb;
	string rowa=seata.substr(0,2);
	string rowb=seatb.substr(0,2);
	cout<<(cara==carb?"1":"0");
	if(cara!=carb){
		cout<<"000";
		return 0;
	}
	cout<<(rowa==rowb?"1":"0");
	if(rowa!=rowb){
		cout<<"00";
		return 0;
	}
	char posa=seata[2];
	char posb=seatb[2];
	cout<<(posa<='C'&&posb<='C'||posa>'C'&&posb>'C'?"1":"0");
	if(!(posa<='C'&&posb<='C'||posa>'C'&&posb>'C')){
		cout<<"0";
		return 0;
	}
	cout<<(posb==near1(posa)||posb==near2(posa)?"1":"0");
	return 0;
}
//100 pts
