#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		if((b[0]-'0')*10+b[1]==(d[0]-'0')*10+d[1]){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='C'){
				if(abs(b[2]-d[2])<=1) cout<<"1111";
				else cout<<"1110";
			}else if(b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F') cout<<"1111";
			else {
				cout<<1100;
			}
		}else{
			if(abs((b[0]-'0')*10+b[1]-(d[0]-'0')*10+d[1])<=1) cout<<"1001";
			else cout<<"1000";
		}
	} 
	else{
		cout<<"0000";
		return 0;	
	} 
} 
