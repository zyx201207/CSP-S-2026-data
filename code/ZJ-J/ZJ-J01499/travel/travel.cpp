#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;
	cin>>a>>b>>a1>>b1;
	
	if(a==a1){
		cout<<1;
		if(b[1]==b1[1]&&b[0]==b1[0]){
			cout<<1;
			if((b[2]<='C'&&b1[2]<='C')||(b[2]>'C'&&b1[2]>'C')){
				cout<<1;
				if(b[2]+1==b1[2]||b[2]-1==b1[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<"000";
		}
		
	}else{
		cout<<"0000";
	}
	
	
	return 0;
}