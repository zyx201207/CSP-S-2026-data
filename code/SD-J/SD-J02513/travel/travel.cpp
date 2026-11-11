#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,aa,bb;
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<1;
		if(aa[0]==bb[0] && aa[1]==bb[1]){
			cout<<1;
			if((aa[2]<'D' && bb[2]<'D') || (aa[2]>'C' && bb[2]>'C')){
				cout<<1;
				if(aa[2]-1==bb[2] || aa[2]==bb[2]-1){
					cout<<1;
				}
				else {
					cout<<0;
				}
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
