#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,z1,z2;
	char s1,s2;
	cin>>c1>>z1>>s1;
	cin>>c2>>z2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<1;
		if(z1!=z2){
			cout<<"000";
		}else{
			cout<<1;
			if(s1>='A' && s1<='C' && s2>='A' && s2<='C'){
				cout<<1;
				if(abs(s1-s2)!=1){
					cout<<0;
				}else{
					cout<<1;
				}
			}else if(s1>='D' && s1<='F' && s2>='D' && s2<='F'){
				cout<<1;
				if(abs(s1-s2)!=1){
					cout<<0;
				}else{
					cout<<1;
				}
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
} 
