#include<bits/stdc++.h>
using namespace std;
///int n[0],m[0];
int a[100001],c[100001];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);//[1001][1001][n][m]
	cin>>a[1]>>a[2]>>a[3];
	cin>>c[1]>>c[2]>>c[3];
	int b=0;
	if(a[1]==c[1]){
		cout<<"0";
		//return 0;
	}else{
		cout<<"1";
		b+=1;
		//return 0;
	}
	if(a[2]=c[2]){
		cout<<"0";
		//return 0;		
	}else{
		cout<<"1";
		b+=1;
		//return 0;
	}
	if((a[2]<='C'&&c[2]<='C')||(a[2]>='D'&&a[2]>='D')){
		cout<<"1";
		b+=1;
		//return 0;		
	}else{
		cout<<"0";
		//return 0;	
	}	

	//cin>>b;
	//cin>>c;
	//cin>>d;
	if(b==3){
		cout<<"1";
		//return 0;
	}else{
		cout<<"0";
		//return 0;	
	}	


//	if(b==d){//if((b[1]==d[1])&&(b[2]==d[2])){
//		cout<<"1";
	//	return 0;
//	}else{
//		cout<<"0";
	//	return 0;
//	}
	//if
	fclose(stdin);
	fclose(stdout);
	return 0;
}; 
