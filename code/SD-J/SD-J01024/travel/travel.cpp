#include<bits/stdc++.h>
using namespace std;
string s,st,d,dt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	 cin>>s>>st>>d>>dt;
	 if(s==d){
	 	cout<<1;
	 	if(st.substr(0,2)==dt.substr(0,2)){
	 		cout<<1;
		 }else{
		 	cout<<"000";
		 	return 0;
		 }
			 if(st[2]>'C'&&dt[2]>'C'){
	 			cout<<1;
			}
	 		else if(st[2]<'D'&&dt[2]<'D'){
	 			cout<<1;
	 		}
	 		else{
	 			cout<<"00";
	 			return 0;
	 		}
	 		if(abs(st[2]-dt[2])==1&&st[2]!='C'&&st[2]!='D'){
	 			cout<<1;
	 		}
			 else{
	 			cout<<0;
			 }
			 }
		 
	 	
	 else{
	 	cout<<"0000";
	 }
	return 0;
}
