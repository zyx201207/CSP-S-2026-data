#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	int f=0;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<'1';
		f=1;
		for(int i=0;i<2;i++){
			if(a1[i]!=b1[i]){
				f=0;
				continue;
			}
		}
		if(f==1){
			cout<<'1';
			if((a1[2]<='C'&&b1[2]<='C')||(a1[2]>'C'&&a1[2]<='F'&&b1[2]>'C'&&b1[2]<='F')){
				cout<<'1';
				if((a1[2]<='C'&&b1[2]<='C')){
					if((a1[2]+1)==b1[2]||(a1[2]-1)==b1[2]){
						cout<<'1';
					}
					else{
						cout<<'0';
					}
				}
				else{
					if((a1[2]=='D'&&(a1[2]+1)==b1[2])||(a1[2]=='F'&&(a1[2]-1)==b1[2])){
						cout<<'1';
					}
					else{
						cout<<'0';
					}
				}
			}
			else{
				cout<<'0'<<'0';
			}
		}
		else{
			cout<<'0'<<'0'<<'0';
		}
	}
	else{
		cout<<'0'<<'0'<<'0'<<'0';
	}
	return 0;
}
