#include<bits/stdc++.h>
using namespace std;
string mx1,mx2,my1,my2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>mx1>>mx2>>my1>>my2;
	if(mx1==my1){
		cout<<1;
		string x2q="";
		x2q+=mx2[0];
		x2q+=mx2[1];
		string y2q="";
		y2q+=my2[0];
		y2q+=my2[1];
		if(x2q==y2q){
			cout<<1;
			char x2h=mx2[2];
			char y2h=my2[2];
			if((x2h<='C'&&y2h<='C')||(x2h>='D'&&y2h>='D')){
				cout<<'1';
				if(x2h=='D'){
					x2h++;
				}
				if(y2h=='D'){
					y2h++;
				}
				if(char(x2h+1)==y2h||char(x2h-1)==y2h){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	} 
	else{
		cout<<"0000";
	}
	return 0;
}
