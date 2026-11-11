#include <bits/stdc++.h>
using namespace std;
void suio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void fio(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}
int a1,a2,b1,b2;
char c1,c2;
int main(){
	suio();
	fio();
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1==a2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b1==b2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(c2-c1)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

