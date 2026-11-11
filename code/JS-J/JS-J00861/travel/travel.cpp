#include <bits/stdc++.h>
using namespace std;
int cnt=1;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string c1,c2,z1,z2;
	cin>>c1>>z1>>c2>>z2;
	for(int i=0;i<int(c1.size());i++){
		if(c1[i]!=c2[i]){
			cnt=0;
			break;
		}
	}
	if(cnt){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	cnt=1;
	for(int i=0;i<2;i++){
		if(z1[i]!=z2[i]){
			cnt=0;
			break;
		}
	}
	if(cnt){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	cnt=1;
	if((z1[2]=='A'||z1[2]=='B'||z1[2]=='C')&&(z2[2]=='A'||z2[2]=='B'||z2[2]=='C')){
		cout<<'1';
	}
	else if((z1[2]=='D'||z1[2]=='E')&&(z2[2]=='D'||z2[2]=='F')){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if((z1[2]=='A'&&z2[2]=='B')||(z1[2]=='B'&&z2[2]=='A')||(z1[2]=='B'&&z2[2]=='C')||(z1[2]=='C'&&z2[2]=='B')||(z1[2]=='D'&&z2[2]=='F')||(z1[2]='F'&&z2[2]=='D')){
		cout<<'1';
	}
	else{
		cout<<"0";
	}
	return 0;
}
