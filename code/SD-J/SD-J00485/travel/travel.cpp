#include<iostream>
#include<cmath> 
#include<cstdio> 
using namespace std;
string c1h,xx1h,c2h,xx2h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1h>>xx1h>>c2h>>xx2h;
	if(c1h==c2h){
		cout<<1;
		if(xx1h[1] == xx2h[1] and xx1h[0]==xx2h[0]){
			cout<<1;
			if((xx1h[2]>='A' and xx1h[2]<='C' and xx2h[2]<='C' and xx2h[2]>='A') or (xx1h[2]>='D' and xx1h[2]<='F' and xx2h[2]<='D' and xx2h[2]>='F')){
				cout<<1;
				if(abs(xx1h[2]-xx2h[2]) ==1 or (xx1h[2]=='D' and xx2h[2]=='F' ) or (xx1h[2]=='F' and xx2h[2]=='D')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
} 
