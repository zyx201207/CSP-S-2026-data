#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2;
	string x1,x2;
	cin>>r1>>r2>>x1>>x2;
	string a;
	string b;
	if(r1==x1){
		cout<<'1';
	}else if(r1!=x1){
		cout<<"0000";
		return 0;
	}
	if(r2[0]==x2[0] && r2[1]==x2[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	a=r2[2];
	b=x2[2];
	if(a[0]=='A' && b[0]=='B'){
		cout<<"11";
		return 0;
	}else if(a[0]=='A'&& b[0]=='C'){
		cout<<"10";
		return 0;
	}else if(a[0]=='B'&& b[0]=='A'){
		cout<<"11";
		return 0;
	}else if(a[0]=='B'&& b[0]=='C'){
		cout<<"11";
		return 0;
	}else if(a[0]=='C'&& b[0]=='A'){
		cout<<"10";
		return 0;
	}else if(a[0]=='C'&& b[0]=='B'){
		cout<<"11";
		return 0;
	}else if(a[0]=='D'&& b[0]=='F'){
		cout<<"11";
		return 0;
	}else if(a[0]=='F'&& b[0]=='D'){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}
