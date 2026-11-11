#include<bits/stdc++.h>
using namespace std;
bool c1(int a,int b){
	if(a==b)	return 1;
	else	return 0;
}
bool c2(string a,string b){
	if(a[0]==b[0]&&a[1]==b[1])	return 1;
	else	return 0;
}
bool c3(string a2,string b2){
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
		if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
			return 1;
		}
	}
	else if(a2[2]=='C'||a2[2]=='D'){
		if(b2[2]=='C'||b2[2]=='D'){
			return 1;
		}
	}
	return 0;
}
bool c4(string a,string b){
	if(a[2]=='A')  if(b[2]=='B')  return 1;
	if(a[2]=='B')  if(b[2]=='A'||b[2]=='C')  return 1;
	if(a[2]=='C')  if(b[2]=='B')  return 1;
	if(a[2]=='D')  if(b[2]=='F')  return 1;
	if(a[2]=='F')  if(b[2]=='D')  return 1;
	return 0;
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;
	cout<<c1(a1,b1);//<<c2(a2,b2)<<c3(a2,b2)<<c4(a2,b2);
	if(c1(a1,b1)==true){
		cout<<c2(a2,b2);
		if(c2(a2,b2)==true){
			cout<<c3(a2,b2);
			if(c3(a2,b2)==true){
				cout<<c4(a2,b2);
			}else	cout<<"0";
		} else	cout<<"00";
	}else	cout<<"000";
	return 0;
}
