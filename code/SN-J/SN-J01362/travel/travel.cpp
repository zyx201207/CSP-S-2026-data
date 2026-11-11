#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b[1]==d[1]&&b[0]==d[0]){
		cout<<1;
		if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
			cout<<1;
		}
	}
	else{
		cout<<"00";
	}
	if(b[2]-d[2]==1||d[2]-b[2]==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
