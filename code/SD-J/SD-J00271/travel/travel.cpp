#include<bits/stdc++.h>
using namespace std;
string sa1,sa2,sb1,sb2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>sa1>>sa2>>sb1>>sb2;
	if(sa1!=sb1){
		cout<<"0000";
	}else{
		cout<<"1";
		if(sa2[0]==sb2[0] and sa2[1]==sb2[1]){
			cout<<"1";
			if(sa2[2]<='C' and sb2[2]<='C'){
				cout<<"1";
				if(abs(sa2[2]-sb2[2])==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(sa2[2]>'C' and sb2[2]>'C'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
}//iterator
