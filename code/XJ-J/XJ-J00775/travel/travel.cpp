#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
		if(c2[1]==c4[1]){
			cout<<"1";
		}else{
			cout<<"0";
		}
			if((c2[2]>='A'&&c4[2]>='A'&&c2[2]<='C'&&c4[2]<='C'||c2[2]=='D'&&c4[2]=='F'&&c2[2]=='F'&&c4[2]=='D')&&(c2[1]==c4[1])){
				cout<<"1";
			}else{
				cout<<"0";
		}
			if((c2[2]+1==c4[2]||c2[2]-1==c4[2])&&c2[1]==c4[1]){
				cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0000";
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
}