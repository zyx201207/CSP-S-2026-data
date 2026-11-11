#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3;
	string c2,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
		if(c2[0]==c4[0] && c2[1]==c4[1]){
			cout<<"1";
			if(c2[2]+c4[2]==138 || c2[2]+c4[2]==131 || c2[2]+c4[2]==132 || c2[2]+c4[2]==133)cout<<"1";
			else cout<<"0";
			if(c2[2]+c4[2]==138 || c2[2]+c4[2]==133 || c2[2]+c4[2]==131)cout<<"1";
			else cout<<"0";
			
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
