#include<bits/stdc++.h>
using namespace std;
string c1,c2;
int a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);
cin>>a>>c1>>b>>c2;
int s1,s2;
s1=c1[0]*10+c1[1];
s2=c2[0]*10+c2[1];
if(a!=b){
	cout<<0000;
	return 0;
}
else if(s1!=s2){
	cout<<1000;
	return 0;
}
else if((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')){
	if((c1[2]=='A'&&c2[2]=='B')||(c1[2]=='B'&&c2[2]=='A')||(c1[2]=='B'&&c2[2]=='C')||(c1[2]=='C'&&c2[2]=='B')){
		cout<<1111;
		return 0;
	}
	else{
		cout<<1110;
		return 0;
	}
}
else if((c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='G')){
	cout<<1111;
	return 0;
}
else {
	cout<<1100;
	return 0;
}
fclose(stdin);
fclose(stdout);
}
