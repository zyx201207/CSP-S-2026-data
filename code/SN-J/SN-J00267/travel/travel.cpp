#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cl,sl,ce,se;
	cin>>cl>>sl>>ce>>se;
	if(cl==ce){
		cout<<"1";
		if(sl[0]==se[0] && sl[1]==se[1]){
			cout<<"1";
			if(sl[2]<=67 && se[2]<=67 || sl[2]>=68 && se[2]>=68){
				cout<<"1";
				if(int(sl[2])+1==se[2] || int(se[2])+1==sl[2]){
					cout<<"1";
				}else{
					cout<<"0";
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
