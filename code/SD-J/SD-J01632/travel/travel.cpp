#include<bits/stdc++.h>
using namespace std;
char c1[5],c2[5],c3[5],c4[5]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=2;i++){
		cin>>c1[i];
	}
	for(int i=1;i<=3;i++){
		cin>>c2[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c3[i];
	}
	for(int i=1;i<=3;i++){
		cin>>c4[i];
	}
	if(c1[1]==c3[1]&&c1[2]==c3[2]){
		cout<<"1";
		if(c2[1]==c4[1]&&c2[2]==c4[2]){
			cout<<"1";
			if((c2[3]=='A'&&c4[3]=='B')||(c2[3]=='B'&&c4[3]=='C')||(c2[3]=='D'&&c4[3]=='F')){
				cout<<"11";
			}
			else if((c2[3]=='B'&&c4[3]=='A')||(c2[3]=='C'&&c4[3]=='B')||(c2[3]=='F'&&c4[3]=='D')){
				cout<<"11";
			}
			else if((c2[3]=='A'&&c4[3]=='C')||(c2[3]=='C'&&c4[3]=='A')){
				cout<<"10";
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
	return 0;
}
