#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,cx,r,x;
	string s;
	cin>>cr>>r>>cx>>x;
		if(cr!=cx){
		cout<<"0000"<<endl;
		return 0;
	}
	if(cr==cx){
		s+="1";
	}
	

	if(r[1]<='9' && r[1]>='0' && x[1]<='9' && x[2]>='0' && r[1]==x[1]){
		s+="1";
	}
	else{
		s+="000";
		cout<<s;
		return 0;
	}
	if(r[2]<='F' && r[2]>='D'&& x[2]<='F' && x[2]>='D' || r[2]<='C' && r[2]>='A'&& x[2]<='C' && x[2]>='A' ){
		s+="1";
	}
	else{
		s+="0";
	}
	if(r[2]=='D' && x[2]=='C' || r[2]=='C' && x[2]=='D'){
		s+="0";
	}
	else if(r[2] != x[2] && r[2]==x[2]+1 || r[2]==x[2]-1){
		s+="1";
	}
	else{
		s+="0";
	}
	cout<<s;
	
	return 0;
}
