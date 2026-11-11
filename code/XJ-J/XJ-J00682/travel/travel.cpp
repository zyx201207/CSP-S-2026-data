#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x;
	cin >> a >> b >> x;
	int c,d;
	string y;
	cin >> c >> d >> y;
	if(a==c){
		cout << 1;
	}else{
		cout << 0000;
		return 0;
	}
	if(b==d){
		cout << 1;
	}else{
		cout << 000;
		return 0;
	}
	if((x=='A'+'0' && y=='A'+'1') || (x=='A'+'0' && y=='A'+'2')|| (x=='A'+'1' && y=='A'+'2') ||(y=='A'+'0' && x=='A'+'1') || (y=='A'+'0' && x=='A'+'2')|| (y=='A'+'1' && x=='A'+'2')||(x=='C' && y=='C'+'2')||(y=='c' && x=='c'+'2')){
		cout<< 1;
	}else{
		cout << 00;
		return 0;
	}
	if((x=='A'&&y=='A'+'1') || (x=='B' && y=='B'+'1') || (x=='D' && y=='D'+'2')||(y=='A'&&x=='A'+'1') || (y=='B' && x=='B'+'1') || (y=='D' && x=='D'+'2'){
		cout << 0;
	}
	return 0;
}