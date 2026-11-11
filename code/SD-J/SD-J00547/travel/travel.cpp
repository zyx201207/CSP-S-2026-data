#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cheR,zuoR,cheX,zuoX;
	cin>>cheR>>zuoR>>cheX>>zuoX;
	if(cheR!=cheX){
		cout<<0000;
	}else{
		cout<<1;
		if(cheR[0]!=cheX[0]||zuoR[1]!=zuoX[1]){
			cout<<000;
		}else{
			cout<<1;
			if((zuoR[2]=='A'||zuoR[2]=='B'||zuoR[2]=='C')&&(zuoX[2]=='A'||zuoX[2]=='B'||zuoX[2]=='C')){
				cout<<1;
				if((zuoR[2]=='A'&&zuoX[2]=='B')||(zuoR[2]=='B'&&zuoX[2]=='C')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if((zuoR[2]=='D'||zuoR[2]=='F')&&(zuoX[2]=='D'||zuoX[2]=='F')){
				cout<<1;
				cout<<0;
			}else{
				cout<<00;
			}
		}
	}
	return 0;
}

