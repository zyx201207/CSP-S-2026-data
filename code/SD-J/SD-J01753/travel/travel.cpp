#include<bits/stdc++.h>
using namespace std;
string rxiang,rzuo,yxiang,yzuo;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rxiang>>rzuo>>yxiang>>yzuo;
	if(rxiang==yxiang){
		cout<<1;
		if(rzuo[0]==yzuo[0] && rzuo[1]==yzuo[1]){
			cout<<1;
			if(rzuo[2]<='C' && yzuo[2]<='C' || rzuo[2]>'C' && yzuo[2]>'C'){
				cout<<1;
				if(rzuo[2]=='A' && yzuo[2]=='B' || rzuo[2]=='B' && yzuo[2]=='C' || rzuo[2]=='C' && yzuo[2]=='B' || rzuo[2]=='B' && yzuo[2]=='A' || rzuo[2]=='D' && yzuo[2]=='F' || rzuo[2]=='F' && yzuo[2]=='D'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		} 
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	
	
	return 0;
}
