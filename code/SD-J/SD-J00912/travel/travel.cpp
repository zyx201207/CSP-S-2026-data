#include<bits/stdc++.h>
using namespace std;
int aa,ab,ba,bb;
char ac,bc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aa>>ab>>ac>>ba>>bb>>bc;
	if(aa==ba){
		cout<<1;
		if(ab==bb){
			cout<<1;
			if((ac<='C'&&ac>='A'&&bc<='C'&&bc>='A')||(ac<='E'&&ac>='D'&&bc<='E'&&bc>='D')){
				cout<<1;
				int x=abs(ac-bc);
				if(x==1){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
