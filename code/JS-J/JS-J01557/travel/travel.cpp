#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int f=0;
	if(a==c){
		cout<<1;
		f=1;
	}else{
		cout<<0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&f==1){
		f=2;
		cout<<1;
	}else{
		cout<<0;
	}
	if(f==2&&(b[2]<'D'&&d[2]<'D' || b[2]>'C'&&d[2]>'C')){
		cout<<1;
		f=3;
	}else{
		cout<<0;
	}
	if(f==3 && abs(int(b[2])-int(d[2]))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
