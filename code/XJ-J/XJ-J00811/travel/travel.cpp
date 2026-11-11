#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char s11,s22;
	cin>>c1>>s1>>s11>>c2>>s2>>s22;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(s11>='A'&&s11<='C'&&s22>='A'&&s22<='C'){
				cout<<1;
				if(int(s11)+1==int(s22)||int(s22)+1==int(s11)){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(s11>='D'&&s11<='F'&&s22>='D'&&s22<='F'){
				cout<<1;
				if(int(s11)+1==int(s22)||int(s22)+1==int(s11)){
					cout<<1;
				}
				else{
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