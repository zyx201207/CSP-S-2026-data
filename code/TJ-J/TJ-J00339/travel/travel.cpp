#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t1,t2;
void pd(){
	if(s1[2]=='A'){
		t1=1;
	}
	if(s1[2]=='B'){
		t1=2;
	}
	if(s1[2]=='C'){
		t1=3;
	}
	if(s1[2]=='D'){
		t1=4;
	}
	if(s1[2]=='F'){
		t1=5;
	}
	if(s2[2]=='A'){
		t2=1;
	}
	if(s2[2]=='B'){
		t2=2;
	}
	if(s2[2]=='C'){
		t2=3;
	}
	if(s2[2]=='D'){
		t2=4;
	}
	if(s2[2]=='F'){
		t2=5;
	}
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int s3=s1[0]+s1[1];
	int s4=s2[0]+s2[1];
	if(s3==s4){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	pd();
	int tt1,tt2;
	if(t1<=3){
		tt1=1;
	}else{
		tt1=2;
	}
	if(t2<=3){
		tt2=1;
	}else{
		tt2=2;
	}
	if(tt1==tt2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(t1-t2)==1&&tt1==tt2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

