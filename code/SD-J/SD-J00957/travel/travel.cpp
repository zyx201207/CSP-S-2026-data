#include<bits/stdc++.h>
using namespace std;
string carr,seatr,carx,seatx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>carr>>seatr>>carx>>seatx;
	if(carr==carx){//是否在同一车厢 
		cout<<"1";
		if(seatr[0]+seatr[1]==seatx[0]+seatx[1]){//是否在同一排 
			cout<<"1";
			if((seatr[2]<='C' && seatr[2]>='A' && seatx[2]<='C' && seatx[2]>='A')||((seatr[2]=='D' && seatx[2]=='F') || seatr[2]=='F' && seatx[2]=='D')){//是否在同一过道 
				cout<<"1";
				if(seatr[2]=='A'){//是否在邻座 
					if(seatx[2]=='B'){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else if(seatr[2]=='B'){
					if(seatx[2]=='A' || seatx[2]=='C'){
						cout<<"1";
					} 
					else{
						cout<<"0";
					}
				}
				else if(seatr[2]=='C'){
					if(seatx[2]=='B'){
						cout<<"1";
					} 
					else{
						cout<<"0";
					}
				}
				else if(seatr[2]=='D'){
					if(seatx[2]=='F'){
						cout<<"1";
					} 
					else{
						cout<<"0";
					}
				}
				else if(seatr[2]=='F'){
					if(seatx[2]=='D'){
						cout<<"1";
					} 
					else{
						cout<<"0";
					}
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
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
