#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool sf = 1;
    if(sf){
    	if(c1==c2){
    		cout << "1";
		}else{
			cout << "0";
			sf = 0;
		}
	}else{
		cout << "0";
	}
	char z1 = s1[2];
	char z2 = s2[2];
	string p1="",p2="";
	for(int i = 0;i<=1;i++){
		p1+=s1[i];
	}
	for(int i = 0;i<=1;i++){
		p2+=s2[i];
	}
    if(sf){
    	if(p1==p2){
    		cout << "1";
		}else{
			cout << "0";
			sf = 0;
		}
	}else{
		cout << "0";
	}	
	if(sf){
    	if(((z1>='A'&&z1<='C')&&(z2>='A'&&z2<='C'))||((z1>='D'&&z1<='F')&&(z2>='D'&&z2<='F'))){
    		cout << "1";
		}else{
			cout << "0";
			sf = 0;
		}
	}else{
		cout << "0";
	}
	if(sf){
     	if((z1=='A'&&z2=='B')||(z2=='A'&&z1=='B')||(z1=='B'&&z2=='C')||(z2=='B'&&z1=='C')||(z1=='D'&&z2=='F')||(z2=='D'&&z1=='F')){
    		cout << "1";
		}else{
			cout << "0";
			sf = 0;
		}
	}else{
		cout << "0";
	}	
	return 0;
}