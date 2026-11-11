#include<bits/stdc++.h>
#define int long long
using namespace std;
string sr,sx;
int cr,cx,nr=0,nx=0;
char lr,lx;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	for(int i=0;i<2;i++){
		nr=nr*10+sr[i]-'0';
	}
	lr=sr[2];
	if(lr=='F') lr--;
	for(int i=0;i<2;i++){
		nx=nx*10+sx[i]-'0';
	}
	lx=sx[2];
	if(lx=='F') lr--;
	if(cr==cx){
		cout<<1;
		if(nr==nx){
			cout<<1;
			if((lr>='A'&&lr<='C'&&lx>='A'&&lx<='C')||(lr>='D'&&lr<='E'&&lx>='D'&&lx<='E')){
				cout<<1;
				if(abs(lx-lr)==1) cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
