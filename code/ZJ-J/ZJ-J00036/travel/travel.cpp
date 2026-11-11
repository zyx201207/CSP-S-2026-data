#include<bits/stdc++.h>
using namespace std;
int f1,f2,f3,f4;
string a,b,c,d;
int cmp(){
	if(b[2]=='A'&&d[2]=='B'){
	   	return 1;
	}
	if(b[2]=='A'&&d[2]=='C'){
	   	return 1;
	}
	if(b[2]=='B'&&d[2]=='A'){
	   	return 1;
	}
	if(b[2]=='B'&&d[2]=='C'){
	   	return 1;
	}
	if(b[2]=='C'&&d[2]=='A'){
	   	return 1;
	}
	if(b[2]=='C'&&d[2]=='B'){
	   	return 1;
	}
	if(b[2]=='D'&&d[2]=='F'){
	   	return 1;
	}
	if(b[2]=='F'&&d[2]=='D'){
	   	return 1;
	}
	return 0;
}
int cmp2(){
	if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
	   	return 1;
	}
	if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'){
	   	return 1;
	}
	if(b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'){
	   	return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		f1=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			f2=1;
	        if(cmp()){
			    f3=1;
	        	if(cmp2()){
	        		f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
