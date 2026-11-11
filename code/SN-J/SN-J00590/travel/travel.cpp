#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a>>b1>>b;
	if(a1==b1){
		if(a[0]==b[0]&&a[1]==b[1]){
			if((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C')){
				if(abs(a[2]-b[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
