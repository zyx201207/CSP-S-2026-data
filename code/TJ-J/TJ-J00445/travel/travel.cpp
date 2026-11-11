#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	int aa=a1[0]-'0'+(a1[1]-'0')*10;
	int bb=b1[0]-'0'+(b1[1]-'0')*10;
	if(a==b){
		cout<<1;
		if(aa==bb){
			cout<<1;
			if(a1[2]<='C'&&b1[2]<='C'){
				cout<<1;
			}	
			else if(a1[2]>'C'&&b1[2]>'C'){
				cout<<1;
			}
			else cout<<0;
		}
		else {
			cout<<0<<0;
		}
		if(aa==bb&&(a1[2]+1==b1[2]||a1[2]-1==b1[2]))cout<<1;
		else if(((a1[2]=='C'&&b1[2]=='C')||(a1[2]=='D'&&b1[2]=='D'))&&(aa+1==bb||aa-1==bb)){
		cout<<1;	
		}
		else cout<<0;
	}
	else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}
