#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,ans;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	b=(c3[0]-'0')*10+(c3[1]-'0');
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	c=(c2[0]-'0')*10+(c2[1]-'0');
	d=(c4[0]-'0')*10+(c4[1]-'0');
	if(c==d){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(c2[2]<='C' && c4[2]>='D'){
		cout<<"00";
		return 0;
	}
	else{
		cout<<1;
	}
	if(abs(c2[2]-c4[2])==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
