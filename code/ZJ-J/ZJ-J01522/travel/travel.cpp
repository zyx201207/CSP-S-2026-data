#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string x1;
		x1+=s1[0];
		x1+=s1[1];
		string x2;
		x2+=s2[0];
		x2+=s2[1];
		if(x1==x2){
			cout<<1;
			char cx=s1[2];
			char cy=s2[2];
			if((cx>='D'&&cy>='D'&&cx<='F'&&cy<='F'&&cx!='E'&&cy!='E')||(cx>='A'&&cy>='A'&&cx<='C'&&cy<='C')){
				cout<<1;
				if(abs(int(cx-cy))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}