#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string a,b;
bool a1 ,a2 ,a3 ,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>c2>>b;
	if(c1==c2){
		cout<<'1';
		a1=1;
	}else{
		cout<<'0';
	}
	if(a[0]==b[0]&&a[1]==b[1]&&a1){
		cout<<'1';
		a2=1;
	}else{
		cout<<'0';
	}
	if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C'&&a2){
		cout<<'1';
		a3=1;
		if(a[2]+1==b[2]+0||b[2]+1==a[2]+0){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else if(a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F'&&a2){
		cout<<'1';
		a3=1;
		if(a[2]+1==b[2]+0||b[2]+1==a[2]+0){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else{
		cout<<'0'<<'0';
	}
	
	return 0;
}