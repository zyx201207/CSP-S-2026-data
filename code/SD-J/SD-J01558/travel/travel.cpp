#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	} else{
		cout<<"0000";
		return 0; 
	}
	string ss1,ss2;
	for(int i=0;i<2;i++){
		ss1+=s1[i];
		ss2+=s2[i];
	}
	if(ss2==ss1){
		cout<<1;
	} else{
		cout<<"000";
		return 0; 
	}
	bool f1=0,f2=0;
	if(s1[2]>='A'&&s1[2]<='C'){
		f1=1;
	}
	if(s2[2]>='A'&&s2[2]<='C'){
		f2=1;
	}
	if(f1==f2){
		cout<<1;
	} else{
		cout<<"00";
		return 0; 
	}
	if(!f1){
		cout<<1;
	}else{
		if(abs(s1[2]-s2[2])==1){
			cout<<1;
		} else{
			cout<<"0";
			return 0; 
		}
	}
	return 0;
} 
