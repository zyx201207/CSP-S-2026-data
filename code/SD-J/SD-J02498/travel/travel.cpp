#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	
	int flag1=0;
	if(a==c){
		cout<<1;
		flag1=1;
	}
	else cout<<0;
	
    
    
   int flag2=0;
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		flag2=1;
	}
	else {
		cout<<0;
	}
	
	int flag3=1;
	char xx=b[2],yy=d[2];
	if(((xx=='C'&&yy=='D')||(xx=='D'&&yy=='C'))||flag2==0){
		cout<<0;
		flag3=0;
	}
	else cout<<1;
	
	if(flag1==1&&flag2==1&&flag3==1&&abs(int(b[2]-d[2])==1)){
		cout<<1;
	}
	else cout<<0;
	
	return 0;
} 
