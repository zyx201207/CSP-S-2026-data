#include<bits/stdc++.h>
using namespace std;
int c1,c2;
void f(string x,string y){
	if(x[2]=='A'&&y[2]=='B'){
		cout<<"11";
		return ;
	}
	if(x[2]=='B'&&y[2]=='C'){
		cout<<"11";
		return ;
	} 
	if(x[2]=='D'&&y[2]=='F'){
		cout<<"11";
		return ;
	} 
	if(y[2]=='A'&&x[2]=='B'){
		cout<<"11";
		return ;
	} 
	if(y[2]=='B'&&x[2]=='C'){
		cout<<"11";
		return ;
	} 
	if(y[2]=='D'&&x[2]=='F'){
		cout<<"11";
		return ;
	}
	else{
		if(x[2]=='A'&&y[2]=='C'||y[2]=='A'&&x[2]=='C'){
			cout<<"10";	
		}else if(x[2]!='A'&&y[2]!='C'||y[2]!='A'&&x[2]!='C'){
			cout<<"00";
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==1||c2==1||c1==16||c2==16){
		cout<<0;
	}
	else{
		if(c1==c2){
			cout<<1;
			if(s1[0]!=s2[0]||s1[1]!=s2[1]){
				cout<<"000";
			}else{
				cout<<1;
				f(s1,s2);
			}
			
		}
		else{
			cout<<"0000";
		}
	}
	return 0;
}

