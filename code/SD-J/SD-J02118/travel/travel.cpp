#include<bits/stdc++.h>
#define ll long long
using namespace std;
string arr,arr2;
string seat,seat2;
ll seatf,seatf2;
char seats,seats2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>arr>>seat;
	cin>>arr2>>seat2;
	seatf=(seat[0]-'0')*10+(seat[1]-'0');
	seatf2=(seat2[0]-'0')*10+(seat2[1]-'0');
	seats=seat[2]; 
	seats2=seat2[2]; 
	if(arr==arr2){
		cout<<"1";
		if(seatf==seatf2){
			cout<<"1";
			if((seats<='C'&&seats>='A'&&seats2<='C'&&seats2>='A')||(seats<='F'&&seats>='D'&&seats2<='F'&&seats2>='D')){
				cout<<"1";
				if(abs(seats-seats2)==1){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
