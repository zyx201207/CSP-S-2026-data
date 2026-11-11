#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			char a1=c2[2],a2=c4[2];
			if((a1=='A'&&a2=='B')||(a1=='A'&&a2=='C')||(a1=='B'&&a2=='C')||(a1=='B'&&a2=='A')||(a1=='C'&&a2=='A')||(a1=='C'&&a2=='B')||(a1=='D'&&a2=='E')||(a1=='E'&&a2=='D')){
				if(a1+1==a2||a1-1==a2){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
