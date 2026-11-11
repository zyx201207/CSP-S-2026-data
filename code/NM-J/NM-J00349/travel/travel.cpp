#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.travel","r",stdin);
	freopen("out.travel","w",stdout);
	int a=0;
	char y[5]={};
	int b=0;
	char x[5]={};
	cin>>a>>x>>b>>y;

	if(a==b&&1<a<16&&1<b<16){
		cout<<"1";	
		if((x[0]-'0')*10+(x[1]-'0')==(y[0]-'0')*10+(y[1]-'0')){
			cout<<"1";
			if(x[2]-'0'<=19&&y[2]-'0'<=19||x[2]-'0'=='D'&&x[2]-'0'=='F'&&y[2]-'0'=='D'&&y[2]-'0'=='F'){
		 		cout<<"1";		
				if(x[2]-'0'<=19&&y[2]-'0'<=19&&x[2]-'0'-(y[2]-'0')==1||y[2]-'0'-(x[2]-'0')==1||x[2]-'0'=='D'||x[2]-'0'=='F'&&y[2]-'0'=='D'||y[2]-'0'=='F'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}	
		
//	cout<<x[2]-'0';
		
		

	
	return 0;
}
