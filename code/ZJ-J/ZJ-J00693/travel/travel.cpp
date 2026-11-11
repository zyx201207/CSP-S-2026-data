#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
string sr,sx;
string br,bx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sr>>br>>sx>>bx;
	if(sr==sx){
		cout<<'1';
		if(br[0]==bx[0]&&br[1]==bx[1]){
			cout<<'1';
			char cr=br[2];
			char cx=bx[2];
			if(cr<='C'&&cx<='C'){
				cout<<'1';
				if(abs(cr-cx)==1)cout<<'1';
				else cout<<'0';
			}
			else if(cr>'C'&&cx>'C')cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
