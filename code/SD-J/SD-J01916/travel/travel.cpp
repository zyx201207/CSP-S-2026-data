#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ax=0,ap=0,bx=0,bp=0;
	char al,bl;
	string sa,sb;
	cin>>ax>>sa;
	al=sa[2];
	for(int i=0;i<2;i++){
		ap=ap*10+sa[i]-'0';
	}
	cin>>bx>>sb;
	bl=sb[2];
	for(int i=0;i<2;i++){
		bp=bp*10+sb[i]-'0';
	}
	if(ax==bx){
		cout<<"1";
		if(ap==bp){
			cout<<"1";
			if((al<='C'&&bl<='C')||(al>='D'&&bl>='D')){
				cout<<"1";
				if(abs(al-bl)==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000"; 
	}
	else cout<<"0000";
	
	return 0;
} 
