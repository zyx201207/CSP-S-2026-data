#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string aa1,bb1,cc1,dd1;
	cin>>aa1>>bb1>>cc1>>dd1;
	if(aa1!=cc1)cout<<"0000";
	else {
		cout<<'1';
		if(bb1[0]==dd1[0]&&bb1[1]==dd1[1]){
			cout<<'1';
			bool ff1=0,ff2=0;
			for(int i=0;i<3;i++){
				if(bb1[2]==char(65+i))ff1=1;
				if(dd1[2]==char(65+i))ff2=1;
			}
			if(ff1==ff2){
				cout<<'1';
				if((bb1[2]=='A'&&dd1[2]=='C')||(bb1[2]=='C'&&dd1[2]=='A'))cout<<'0';
				else cout<<'1';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
}

