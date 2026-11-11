#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
int s=0;
cin>>a>>b>>c>>d;
	if(a==c){
		s+=1000;
	if(b[0]==d[0]&&b[1]==d[1]){
		s+=100;
	if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'||b[2]=='C'&&d[2]=='A'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
		s+=10;
	if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
		s+=1;	
			}
		}
	}	
}
if(s==0){
	cout<<"0000"<<endl;
}else{
	cout<<s<<endl;
}
return 0;	
} 
