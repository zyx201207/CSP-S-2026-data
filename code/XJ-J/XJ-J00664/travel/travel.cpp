#include<bits/stdc++.h>
using namespace std;

string cc1,cc2,ss1,ss2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cc1>>cc2>>ss1>>ss2;
	
	string a,b;
	a+=cc2[0];
	a+=cc2[1];
	b+=ss2[0];
	b+=ss2[1];
	if(cc1==ss1){
		cout<<1;
		if(a==b){
			cout<<1;
			if((cc2[2]<='C'&&ss2[2]<='C')||(cc2[2]>='D'&&ss2[2]>='D')){
				cout<<1;
				if(abs(cc2[2]-ss2[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}