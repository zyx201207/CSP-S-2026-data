#include<bits/stdc++.h>
using namespace std;
int num1,num2,num3,num4;
int flag1,flag2,flag3,flag4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int x=c1.size();
	int y=c2.size();
	int z=c3.size();
	int zz=c4.size();
	for(int i=0;i<x;i++){
		int u=c1[i]-'0';
		if(i==0) num1+=u*10;
		else num1+=u;
	}
	for(int i=0;i<z;i++){
		int u=c3[i]-'0';
		if(i==0) num3+=u*10;
		else num3+=u;
	}
	if(num1==num3){
		cout<<1;
		flag1=1;
	} 
	else{
	    cout<<"0000";
		return 0;//true
	} 
	for(int i=0;i<y-1;i++){
		int u=c2[i]-'0';
		if(i==0) num2+=u*10;
		else num2+=u;
	} 
	for(int i=0;i<zz-1;i++){
		int u=c4[i]-'0';
		if(i==0) num4+=u*10;
		else num4+=u;
	}
	if(num2==num4){
		cout<<1;
		flag2=1;
	} 
	else{
	    cout<<0;//true
	} 
	if(flag2==1&&((c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C')||(c2[2]>='D'&&c2[2]<='F'&&c4[2]>='D'&&c4[2]<='F'))){
		cout<<1;
	}
	else{
		cout<<0;//ture
	}
    if(flag1==1&&flag2==1&&((c2[2]>='A'&&c2[2]<='B'&&c4[2]>='A'&&c4[2]<='B')||(c2[2]>='D'&&c2[2]<='F'&&c4[2]>='D'&&c4[2]<='F')||(c2[2]>='B'&&c2[2]<='C'&&c4[2]>='B'&&c4[2]<='C'))){
    	cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
