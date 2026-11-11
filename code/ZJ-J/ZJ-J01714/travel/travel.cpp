#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<"0000"<<endl;
	}
	else{
		cout<<'1';
		if(b2[0]==a2[0]&&a2[1]==b2[1]){
			cout<<'1';
			if(b2[2]>='D'&&a2[2]>='D'||b2[2]<'D'&&a2[2]<'D'){
				cout<<"1";
				if(a2[2]>='D'){
					cout<<'1'<<endl;
				}
				else if(abs(a2[2]-b2[2])!=2){
					cout<<'1'<<endl;
				}
				else{
					cout<<'0'<<endl;
				}
			}
			else{
				cout<<"00"<<endl;
			}
		}
		else{
			cout<<"000"<<endl;
		}
	}
	return 0;
}
