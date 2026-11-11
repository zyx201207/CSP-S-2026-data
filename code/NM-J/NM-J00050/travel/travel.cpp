#include<bits/stdc++.h> 
using namespace std;
int main(){
freopen("travel.in","r",stdin);	
freopen("travel.out","w",stdout);		
char n[4];
char b[4];
int a1=0;
int a2=0;
int a3=0;
for(int i=0;i<=4;i++){
	cin>>n[i];

}	
cout<<endl;
for(int i=0;i<=4;i++){
	cin>>b[i];
	
}		
	if(n[0]==b[0]&&n[1]==b[1]){
		cout<<1;
		a1=1;
	}else{
		cout<<0;
		a1=0;
	}
	
	
	if(n[2]==b[2]&&n[3]==b[3]&&a1==1){
		cout<<1;
		a2=1;
	}else{
		cout<<0;
	}
	
		if(((n[4]=='A'||n[4]=='B'||n[4]=='C')&&(b[4]=='A'||b[4]=='B'||b[4]=='C')&&a1==1&&a2==1)||(n[4]=='D'||n[4]=='F')&&(b[4]=='D'||b[4]=='F')&&a1==1&&a2==1){
		cout<<1;
		a3=1;
	}else{
		cout<<0;
		 
		
	}
	if(((n[4]=='A'&&b[4]=='B')||(n[4]=='B'&&b[4]=='A')||(n[4]=='B'&&b[4]=='C')||(n[4]=='C'&&b[4]=='B')||(n[4]=='D'&&b[4]=='F')||(n[4]=='F'&&b[4]=='D'))&&a1==1&&a2==1&&a3==1){
		cout<<1;
	}else{
		cout<<0;
	}

	cout<<endl;

	
	
	
	return 0;
}
