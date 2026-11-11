#include<bits/stdc++.h>
using namespace std;
int cnt,a,c;
string b,d; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	for(int i=0;i<3;i++){
		if('A'+i==b[2]){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				cout<<1;
				break;
			}
			else{
				cout<<0;
				break;
			}
		}
	}
	if(abs(b[2]-b[2])==1){
		cout<<1;
		return 0;
	}
	else{
		cout<<0;
		return 0; 
	}
	if(b[2]=='D'||b[2]=='F'){
	    if(d[2]=='D'||d[2]=='F'){
	    	cout<<11;
	    	return 0;
		}
		else{
			cout<<00;
			return 0;
		}
	}
	return 0;
} 
