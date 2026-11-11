#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y,w,q;
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		x+=a[i]-'0';
		y+=c[i]-'0';
		w+=b[i]-'0';
		q+=d[i]-'0';
	}
	if(x==y){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(w==q){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&b[2]>='A'&&d[2]>='A'&&d[2]<='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
