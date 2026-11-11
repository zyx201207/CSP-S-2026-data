#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string chea,zuoa,cheb,zuob;
	cin>>chea>>zuoa>>cheb>>zuob;
	if(chea!=cheb){
		cout<<"0000";	
		return 0;
	} 
	if(zuoa[0]!=zuob[0]||zuoa[1]!=zuob[1]){
		cout<<"1000";
		return 0;
	}
	if(((zuoa[2]=='A'||zuoa[2]=='B'||zuoa[2]=='C')&&(zuob[2]=='A'||zuob[2]=='B'||zuob[2]=='C'))||((zuoa[2]=='D'||zuoa[2]=='F')&&(zuob[2]=='D'||zuob[2]=='F'))){}
	else{
		cout<<"1100";
		return 0;
	}
	if(zuoa[2]=='B'||zuoa[2]=='D'||zuoa[2]=='F'||zuob[2]=='B'){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
