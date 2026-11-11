#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x,y;
	x=b[2];
	y=d[2];
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
		
	}
	else{
		cout<<"0";
	}
	if(b[2]==d[2]||b[1]==d[1]&&b[0]==d[0]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]&&x-y==1||x-y==-1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
}
