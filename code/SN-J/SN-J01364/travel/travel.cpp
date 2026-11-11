#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		if(a2[0]==b2[0] && a2[1]==b2[1]){
			cout<<1;
			int a=a2[2]-'A',b=b2[2]-'A';
			if((a/3<1 && b/3<1)||(a/3==1 & b/3==1)){
				cout<<1;
				if(abs(a-b)==1){
					cout<<1;
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
} 
