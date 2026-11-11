#include<bits/stdc++.h>
using namespace std;
string cara,carb,posa,posb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cara>>posa>>carb>>posb;
	if(cara!=carb){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(posa[0]==posb[0]&&posa[1]==posb[1]){
			cout<<"1";
			bool fa=(posa[2]<='C');
			bool fb=(posb[2]<='C');
			if(fa==fb){
				cout<<"1";
				if(fa==0||(abs(posa[2]-posb[2])==1)){
					cout<<"1";
				}
				else cout<<"0";
				return 0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
}
