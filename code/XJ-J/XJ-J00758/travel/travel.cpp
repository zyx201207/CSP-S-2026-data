#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	int cxa,cxb,pa,pb;
	char zwa,zwb;
	cin>>cxa>>pa>>zwa>>cxb>>pb>>zwb;
	if(cxa==cxb){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(pa==pb){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	bool cf=0;
	if(pa==pb){
		if((zwa=='D'&&zwb=='F')||(zwa=='F'&&zwb=='D')){
			cf=1;
		}
		if((zwa=='A'&&zwb=='B')||(zwa=='A'&&zwb=='C')||(zwa=='B'&&zwb=='C')||(zwa=='B'&&zwb=='A')||(zwa=='C'&&zwb=='A')||(zwa=='C'&&zwb=='B')){
			cf=1;
		}
	}
	if(cf==1){
		cout<<1;
		if((zwa=='D'&&zwb=='C')||(zwa=='C'&&zwb=='D')){
			cout<<0;
			return 0;
		}
		if(abs(zwa-zwb)==1){
			cout<<1;
		}
	}else{
		cout<<"00";
		return 0;
	}
}