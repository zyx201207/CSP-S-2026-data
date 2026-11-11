 #include<bits/stdc++.h>
 using namespace std;
 char c1[3];
 char c2[3]; 
 int main(){
 	ios::sync_with_stdio(false);cin:(0);cout:(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0;
	int s1,s2;
	cin>>s1;
	for(int i=1 ;i<=3;i++){
		cin>>c1[i];
	}
	cin>>s2;
	for(int i=1;i<=3;i++){
		cin>>c2[i];
	}
	if(s1==s2){
		 a=1;
	}
	if(a!=1){
		cout<<"0000";
		return 0;
	}
	if(c1[1]==c2[1] and c1[2]==c2[2]){
		b=1;
	}
	if(b!=1){
		cout<<"1000";
		return 0;
	}
	if(c1[3]=='A' or c1[3]=='B' or c1[3]=='C' and c2[3]=='A' or c2[3]=='B' or c2[3]=='C'){
		c=1;
	}
	if(c1[3]=='E' or c1[3]=='F' and c2[3]=='E' or c2[3]=='F'){
		c=1; 
	}
	if(c!=1){
		cout<<"1110";
		return 0;
	}
	if(c1[3]=='A' and c2[3]=='B'){
		d=1; 
	}
	if(c1[3]=='B' and c2[3]=='C' ){
		d=1;
	}
	if(c1[3]=='C' and c2[3]=='B'){
		d=1; 
	}
	if(c1[3]=='B' and c2[3]=='A'){
		d=1; 
	}
	if(c1[3]=='E' and c2[3]=='F'){
		d=1; 
	}
	if(c1[3]=='F' and c2[3]=='E'){
		d=1; 
	}
	cout<<a<<b<<c<<d;
 	return 0;
 	
 }
