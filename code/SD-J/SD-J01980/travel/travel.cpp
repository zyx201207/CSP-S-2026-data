#include<bits/stdc++.h>
using namespace std;
int jdz(int x){
	if(x>=0) return x;
	else return -x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	int pr=0,px=0,zr,zx;
	if(sr[2]!='F') zr=sr[2]-'A'+1;
	else zr=5;
	if(sx[2]!='F') zx=sx[2]-'A'+1;
	else zx=5;
	for(int i=0;i<=1;i++){
		pr=pr*10+(sr[i]-'0');
		px=px*10+(sx[i]-'0');
	}
 	if(cr==cx){
		cout<<1;
		if(pr==px){
			cout<<1;
			if(zr<4&&zx<4){
				cout<<1;
				if(jdz(zr-zx)==1){
					cout<<1;
				}
				else cout<<0;
			}
			else{
				if(zr>3&&zx>3){
					cout<<"11";
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
