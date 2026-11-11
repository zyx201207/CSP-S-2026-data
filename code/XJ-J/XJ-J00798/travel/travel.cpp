#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    bool xiang=0,pai=0,ce=0;
    if(s1==s2){
    	cout<<1;
    	xiang=1;
	}else{
		cout<<0;
	}
	if(xiang==1&&c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		pai=1;
	}else{
		cout<<0;
	}
	if(xiang==1&&pai==1){
		if(c1[2]>='A'&&c1[2]<='C'&&c2[2]>='A'&&c2[2]<='C'){
			cout<<1;
			ce=1;
		}else if(c1[2]>='D'&&c1[2]<='F'&&c2[2]>='D'&&c2[2]<='F'){
			cout<<1;
			ce=1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(xiang==1&&pai==1&&ce==1){
		if(c1[2]+1==c2[2]||c2[2]+1==c1[2]){
			cout<<1;
		}else{
		cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}