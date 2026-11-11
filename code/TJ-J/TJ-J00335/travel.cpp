#include<bits/stdc++.h>
using namespace std;
int main ( ){
	
	string a[5],b;
	char d[30];
	int c;
	int e;
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		b=a[2];
		d[i]=b[c];
		c++;
	}
	for(int i=1;i<=3;i++){
		b=a[4];
		d[i]=b[c];
		c++;
	}
	if(a[1]==a[3]){
		cout<<1;
		
	}
	else{
		cout<<0;
	}
	if(d[1]+d[2]==d[4]+d[5]){
		cout<<1;
		
	}
	else{
		cout<<0;
	}
	if(d[3]=='A'&&d[3]=='B'&&d[3]=='C'){
		if(d[6]=='A'&&d[6]=='B'&&d[6]=='C'){
			cout<<1;
		}
	}
	else{
	if(d[3]=='D'&&d[3]=='F'){
		if(d[6]=='D'&&d[6]=='F'){
			cout<<1;
		}
	}
	else{
		cout<<0;
	}
	}
	
	if(d[3]-d[6]==1&&d[6]-d[3]==1){
		cout<<1;
		
	}
	else{
		cout<<0;
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
return 0;
}
