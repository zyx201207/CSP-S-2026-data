#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char  a[10],b[10],c[10],d[10];
	int   j[5]={0,0,0,0,0};
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a[1]==c[1]&&a[2]==c[2]){
		j[1]=1;
		
		if(b[1]==d[1]&&b[2]==d[2]){
			j[2]=1;
			
			if(b[3]<='C'&&d[3]<='C'){
				j[3]=1;
				if(b[3]==d[3]-1||b[3]==d[3]+1){
				j[4]=1;}
				else j[4]=0;
			}
			if(b[3]>='D'&&d[3]>='D'){
				j[3]=1;
				if(b[3]==d[3]-1||b[3]==d[3]+1){
					j[4]=1;}
				if(b[3]!=d[3]-1||b[3]!=d[3]+1){
					j[4]=0;}
			}
			//else j[3]=0;	
		}
		else j[2]=0;
	}
	else j[1]=0 ;
	
	
	for(int i=1;i<=4;i++){
	cout<<j[i];
	}
	return 0;
}
