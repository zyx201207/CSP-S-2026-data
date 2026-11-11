#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if (rc==xc){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if (rc==xc && rs[0]==xs[0] && rs[1]==xs[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if (rc==xc && rs[0]==xs[0] && rs[1]==xs[1] && (rs[2]<='C' && xs[2]<='C' || rs[2]>'C' && xs[2]>'C')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if (rc==xc && rs[0]==xs[0] && rs[1]==xs[1] && (rs[2]<='C' && xs[2]<='C' || rs[2]>'C' && xs[2]>'C') && (rs[2]+1==xs[2] || xs[2]+1==rs[2])){
		cout<<1;
	}   
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);                    
	return 0;
} 
