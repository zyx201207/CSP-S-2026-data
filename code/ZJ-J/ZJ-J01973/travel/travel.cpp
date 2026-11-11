#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int aleft=0,bleft=0,flag=0;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
		flag=1;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&flag==0){
		cout<<1;
	}else{
		cout<<0;flag=1;
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		aleft=1;
	}else{
		aleft=0;
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		bleft=1;
	}else{
		bleft=0;
		flag=1;
	}
	if(aleft==bleft&&flag==0){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(abs(b[2]-d[2])==1&&flag==0){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}