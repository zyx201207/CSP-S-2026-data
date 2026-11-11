#include<bits/stdc++.h>
using namespace std;
string id_R,seat_R;
string id_X,seat_X;
int seat[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	seat[int('D')]=1;
	seat[int('F')]=1;
	cin>>id_R>>seat_R;
	cin>>id_X>>seat_X;
	if(id_R==id_X){
		cout<<"1";
		if(seat_R[0]==seat_X[0]&&seat_R[1]==seat_X[1]){
			cout<<"1";
			if(seat[seat_R[2]]==seat[seat_X[2]]){
				cout<<"1";
				if(abs(seat_R[2]-seat_X[2])==1){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
