#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,t1,c2,t2;
	cin>>c1>>t1>>c2>>t2;
	if(c1==c2){
		cout<<"1";
		if(t1[0]==t2[0]&&t1[1]==t2[1]){
			cout<<"1";
			if((t1[2]<='C'&&t2[2]<='C')||(t1[2]>='D'&&t2[2]>-'D')){
				cout<<"1";
				if(abs(t1[2]-t2[2])==1) cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
