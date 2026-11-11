#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	string r4,x4;
	int r3=int(r2[2]);
	int x3=int(x2[2]);
	r4=r2[0]+r2[1];
	x4=x2[0]+x2[1];
	if(r1==x1){
		if(r4==x4){
			if(((x3>=65&&x3<=67)&&(r3>=65&&r3<=67))||((x3==68||x3==70)&&(r3==68||r3==70))){
				if(((x3+r3==131)||(x3+r3==133))||((x3==68||x3==70)&&(r3==68||r3==70))){
					freopen("travel.out","w",stdout);
					cout<<"1111";
					
				}else{
					freopen("travel.out","w",stdout);
					cout<<"1110";
				}
			}else{
				freopen("travel.out","w",stdout);
				cout<<"1100";
			}
		}else{
			
			freopen("travel.out","w",stdout);
			cout<<"1000";
			             
		}
	}else{
		freopen("travel.out","w",stdout);
		cout<<"0000";
		
	}
	return 0;
}