#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
		if(c2[1]+c2[0]==c4[1]+c4[0]){
			cout<<"1";
			if((int(c2[2])>=68&&int(c4[2])>=68)||int(c2[2])<68&&int(c4[2])<68){
				cout<<"1";
				if(int(c2[2])>=68&&int(c4[2])>=68){
					cout<<"1";
				}else if(int(c2[2]+1)==int(c4[2])||int(c2[2]-1)==int(c4[2])){
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
	return 0;
} 
