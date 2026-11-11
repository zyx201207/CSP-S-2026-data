#include<iostream>
using namespace std;
int ax,bx,ah,bh;
char au1,au2,bu1,bu2,az1,az2,bz1,bz2,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>au1>>au2>>az1>>az2>>a>>bu1>>bu2>>bz1>>bz2>>b;
	ax=au1*10+au2-528;
	bx=bu1*10+bu2-528;
	ah=az1*10+az2-528;
	bh=bz1*10+bz2-528;
	if(ax!=bx){
		cout<<"0000";
	}
	else{
		cout<<"1";
		if(ah!=bh){
			cout<<"000";
		}
		else{
			cout<<"1";
			if(a<'D'&&b<'D'){
				cout<<"1";
				if((a=='C'&&b=='A')||(a=='A'&&b=='C')){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
			else if(a>'C'&&b>'C'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}