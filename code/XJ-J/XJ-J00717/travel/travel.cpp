#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[2],b[3],c[2],d[3];
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')){
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	if(b[2]+1==d[2]||b[2]-1==d[2]){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
