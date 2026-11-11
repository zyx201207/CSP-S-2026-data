#include<bits/stdc++.h>
using namespace std;
int aaa[10];
int bbb[10];
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,e;
	string s1,s2,s3,s4,s;
	cin>>s1>>s2>>s3>>s4;
	bool bb = true;
	if(s1 == s3){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	
	
	
	for (int i = 0;i<2;i++){
		aaa[i] = int(s2[i])-48;
	}
	for (int i = 0;i<2;i++){
		bbb[i] = int(s4[i])-48;
	}
	for (int i = 0;i<2;i++){
		if(aaa[i]!=bbb[i]){
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	
	
	
	if(s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C'){
		a = 0;
	}
	else{
		a = 1;
	}
	if(s4[2] == 'A' or s4[2] == 'B' or s4[2] == 'C'){
		b = 0;
	}
	else{
		b = 1;
	}
	if(a == b){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(a == 1){
		cout<<1;
	}
	else{
		if(s2[2] == 'A'){
			a = 0;
		}
		if(s2[2] == 'B'){
			a = 1;
		}
		if(s2[2] == 'C'){
			a = 2;
		}
		if(s4[2] == 'A'){
			b = 0;
		}
		if(s4[2] == 'B'){
			b = 1;
		}
		if(s4[2] == 'C'){
			b = 2;
		}
		if(abs(a-b)>1){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	return 0;
} 
