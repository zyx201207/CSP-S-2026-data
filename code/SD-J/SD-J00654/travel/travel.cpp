#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool w,x,y,z,h,j;
	w=a[0]*10+a[1]==c[0]*10+c[1];
	x=b[0]*10+b[1]==d[0]*10+d[1];
	y=b[2]>='A'&&d[2]>='A'&&b[2]<='C'&&d[2]<='C';
	z=b[2]>='D'&&d[2]>='D';
	h=b[2]+1==d[2];
	j=b[2]-1==d[2];
	if(w){
		cout<<1;
	}else{
		cout<<0;
	}
	if(w&&x){
		cout<<1;
	}else{
		cout<<0;
	}
	if(w&&x&&y||w&&x&&z){
		cout<<1;
	}else{
		cout<<0;
	}
	if(y&&h&&x&&w||y&&j&&x&&w||z&&h&&x&&w||z&&j&&x&&w){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
