#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	cin>>a;
	string a1;
	cin>>a1;
	int b;
	cin>>b;
	string b1;
	cin>>b1;
	int flag=0;
	int flag1=0;
	int flag2=0;
	if (a==b){
		cout<<1;
	}
	else{
		flag=1;
		cout<<0;
	}
	
	
	
	if (a1[0]==b1[0] && a1[1]==b1[1] && flag==0){
		cout<<1;
		
	}
	else{
		flag1=1;
		cout<<0;
	}
	
	
	
	
	if (((a1[2]<='C' && b1[2]<='C' ) || (a1[2]>='D' && b1[2]>='D' ))&& (flag==0) && (flag1==0)){
		cout<<1;
		
	}
	else{
		flag2=1;
		cout<<0;
	}
	
	
	
	if ((a1[2]=='C' && b1[2]=='B' || a1[2]=='B' && b1[2]=='A' || a1[2]=='B' && b1[2]=='C'  || a1[2]=='A' && b1[2]=='B' || a1[2]=='D' && b1[2]=='F' ||a1[2]=='F' && b1[2]=='D')&& flag2==0 ){
		cout<<1;
		
	}
	else{
		cout<<0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);



}

