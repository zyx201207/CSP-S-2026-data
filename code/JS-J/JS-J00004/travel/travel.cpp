#include<bits/stdc++.h>
using namespace std;
string s11,s12,s21,s22;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//main
	cin>>s11>>s12>>s21>>s22;
	if(s11==s21){
		cout<<"1";
		if(s12[0]==s22[0]&&s12[1]==s22[1]){
			cout<<"1";
			if((s12[2]<='C'&&s22[2]<='C')||(s12[2]>'C'&&s22[2]>'C')){
				cout<<"1";
				if(s12[2]-s22[2]==1||s12[2]-s22[2]==-1){
					cout<<"1";
				}else{
					cout<<"0";
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
	
	cout<<'\n';
	return 0;
}
//100
