#include<bits/stdc++.h>
#define int long long
using namespace std;
int cr,cx,zr,zx;
int r,x;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c;
	cin>>c;
	cr+=c-'0';
	cin>>c;
	cr*=10;
	cr+=c-'0';
	
	cin>>c;
	zr+=c-'0';
	cin>>c;
	zr*=10;
	zr+=c-'0';
	
	cin>>c;
	r=c-'A';
	
	cin>>c;
	cx+=c-'0';
	cin>>c;
	cx*=10;
	cx+=c-'0';
	
	cin>>c;
	zx+=c-'0';
	cin>>c;
	zx*=10;
	zx+=c-'0';
	
	cin>>c;
	x=c-'A';
	
	if(cr!=cx){
		cout<<"0000"<<'\n';
		return 0;
	}
	cout<<1;
	if(zr!=zx){
		cout<<"000\n";
		return 0;
	}
	cout<<1;
	if((r<=2&&x<=2)||(r>=3&&x>=3)){
		cout<<1;
	}else{
		cout<<"00\n";
		return 0;
	}
	if(abs(r-x)==1){
		cout<<1<<'\n';
		return 0;
	}else{
		cout<<"0\n";
		return 0;
	}
	return 0;
}
 
