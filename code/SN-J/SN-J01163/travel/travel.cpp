#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string aa,bb;
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<"1";
		if(aa[1]==bb[1]&&aa[0]==bb[0]){
			cout<<"1";
			if(aa[2]<='C'&&bb[2]<='C'){
				if(aa[2]=='C'&&bb[2]=='A'||aa[2]=='A'&&bb[2]=='C'){
					cout<<"10";
					return 0;
				}else{
					cout<<"11";
					return 0;
				}
			}else if(aa[2]>'C'&&bb[2]>'C'&&aa[2]<='F'&&bb[2]<='F'){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
