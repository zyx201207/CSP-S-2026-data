//刘子墨SN-J00731西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int ge;
string ax,xx,aw,xw;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>aw>>xx>>xw;
	if(ax==xx){
		cout<<1;
		if(aw[0]==xw[0]&&aw[1]==xw[1]){
			cout<<1;
			if((aw[2]>='D'&&xw[2]>='D')||(aw[2]<='C'&&xw[2]<='C')){
				cout<<1;
				if(abs(int(aw[2]-xw[2]))==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}			
		}
		else{
			cout<<0<<0<<0;
		}		
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
