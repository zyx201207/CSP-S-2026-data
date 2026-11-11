#include<bits/stdc++.h>
using namespace std;
string r,x,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>a>>x>>b;
	if(r != x){
		cout<<"0000";
		
	}else if(a[0] != b[0] || a[1] != b[1]){
		cout<<"1000";
	}else if(a[2] == b[2]){
		cout<<"1110";
	}else if(a[2] =='A'&&b[2] == 'D'){
		cout<<"1100";
		
	}else if(a[2] =='A'&&b[2] == 'E'){
		cout<<"1100";
	}else if(a[2] =='B'&&b[2] == 'D'){
		cout<<"1100";
	}else if(a[2] =='B'&&b[2] == 'E'){
		cout<<"1100";
	}else if(a[2] =='C'&&b[2] == 'D'){
		cout<<"1100";
	}else if(a[2] =='C'&&b[2] == 'E'){
		cout<<"1100";
	}else if(a[2] =='D'&&b[2] == 'A'){
		cout<<"1100";
	}else if(a[2] =='D'&&b[2] == 'B'){
		cout<<"1100";
	}else if(a[2] =='D'&&b[2] == 'C'){
		cout<<"1100";
	}else if(a[2] =='E'&&b[2] == 'A'){
		cout<<"1100";
	}else if(a[2] =='E'&&b[2] == 'B'){
		cout<<"1100";
	}else if(a[2] =='E'&&b[2] == 'C'){
		cout<<"1100";
	}else if(a[2] == 'A' && b[2] == 'C'){
		cout<<"1110";
	}else if(a[2] == 'C' && b[2] == 'A'){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	
 	
	return 0;
}
