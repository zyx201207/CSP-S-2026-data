#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
    }    
    if(b[0]+b[1]==d[0]+d[1]){
    	cout<<"1";
    }
    else{
    	cout<<"000";
    	return 0;
	}
	if((b[2]<=3&&d[2]<=3)||(b[2]>=4&&d[2]>=4)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if((b[2]>=4&&d[2]>=4)||b[2]!=d[2]){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
