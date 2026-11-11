#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,x1,x2;
	string a,b;
	cin>>x>>a>>y>>b;
	if(a[2]<='C'){
		x1=1;
	}else{
		x1=0;
	}
	if(b[2]<='C'){
		x2=1;
	}else{
		x2=0;
	}
	if(x==y){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(x1==x2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs((int)a[2]-b[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
