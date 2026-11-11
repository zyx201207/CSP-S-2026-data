#include<bits/stdc++.h>
using namespace std;

string cone1,sone1,ctwo2,stwo2;
int s1ma,s2ma;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cone1>>sone1>>ctwo2>>stwo2;
	s1ma=(sone1[0]-48)*10+(sone1[1]-48);
	s2ma=(stwo2[0]-48)*10+(stwo2[1]-48);
	if(cone1==ctwo2){
		cout<<1;
		if(s1ma==s2ma){
			cout<<1;
			if((sone1[2]>='D' && stwo2[2]>='D')||(
				sone1[2]<'D' && stwo2[2]<'D')){
				cout<<1;
				if(abs(sone1[2]-stwo2[2])==1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
