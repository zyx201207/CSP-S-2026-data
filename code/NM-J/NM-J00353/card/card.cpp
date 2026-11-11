#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int q1,q2;
    string K1,K2;
    cin>>q1>>K1>>q2>>K2;
    if(q1 == q2){
        cout<<"1";
    }else{
    cout<<"0000";
    return 0;
    }
	if((K1[0]==K2[0])&&(K1[1] == K2[1])){
		cout << "1";
	}else{
		cout<<"000";
		return 0;
	}
	int f = K1[2];
	int e = K2[2];
	if((f>='A'&&e<='C')||(f>='C'&&e<='A' )||(f>='D'&&e<='E')||(f>='E'&&e<='D')){
		cout << "1";
	}else{
		cout<<"00";
		return 0;
	}
	if((f=='A'&&e=='B')||(f=='B'&&e=='C')||(f=='C'&&e=='B')||(f=='E'&&e=='D')||(f=='B'&&e=='A')||(f=='D'&&e=='E')){
		cout << "1";
	}else{
		cout<<"0";
	}


    return 0;
}
