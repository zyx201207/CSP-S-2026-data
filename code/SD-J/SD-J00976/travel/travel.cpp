#include<bits/stdc++.h>
using namespace std;

string zhangx,zhangr,gongx,gongr; 
bool cnt1(int a,int b){
	if((a=='A'&&b=='B')||(a=='D'&&b=='C')||(a=='C'&&b=='D')||(a=='B'&&b=='A')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))
		return true;
	else return false;
}
bool q,d,c,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>zhangx>>gongx>>zhangr>>gongr;
	
	if(zhangx==zhangr){
		cout<<1;
	
		if(gongx[0]==gongr[0]&&gongx[1]==gongr[1]){
			cout<<1;
		
			if((gongx[2]>='D'&&gongr[2]>='D')||(gongx[2]<='C'&&gongr[2]<='C')){
				cout<<1;
			
				if(cnt1(gongx[2],gongr[2])){
					cout<<1;
				}
				else{
					cout<<0<<endl;
					return 0;
				}
			}
			else {
				cout<<00<<endl;
				return 0; 
			}
		}
		else{
			cout<<000<<endl;
			return 0;
		}
	}
	else {
		cout<<0000;
		return 0;
	}
	
	return 0;
} 
//zgh
