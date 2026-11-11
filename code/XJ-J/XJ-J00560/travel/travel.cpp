#include<bits/stdc++.h>
using namespace std;
struct node{
	string x;
	string y;
};
struct node a[3];
int main(){
	string s="";
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1].x>>a[1].y>>a[2].x>>a[2].y;
	if(a[1].x==a[2].x){
		s+="1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a[1].y[0]==a[2].y[0] and a[1].y[1]==a[2].y[1]){
		s+="1";
		if(a[1].y[2]<='C' and a[2].y[2]<='C' or a[1].y[2]>'C' and a[2].y[2]>'C'){
			s+="1";
		}else{
			s+="0";
		}
	}else{
		s+="0";
		s+="0";
	}
	if(s[2]=='1'){
		if(a[1].y[2]==a[2].y[2]+1 or a[1].y[2]==a[2].y[2]-1){
			s+="1";	
		}else{
			s+="0";
		}
	}else{
		s+="0";
	}
	cout<<s;
	return 0;
}