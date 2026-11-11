#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	bool isTong = false;			// 是否位于同一车厢 
	bool isPai = false;				// 是否位于同一排 
	bool isCe = false;				// 是否同侧 
	if(c1==c2){
		cout<<1;
		isTong = true;
	}
	else cout<<0;
	
	if(isTong&&s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
		isPai = true;
	}
	else cout<<0;
	
	if(isTong&&isPai){
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
			cout<<1;
			isCe = true;
		} else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
			cout<<1;
			isCe = true;
		} else{
			cout<<0;
		}
	} else{
		cout<<0;
	}
	
	if(isTong&&isPai&&isCe){
		if(abs(s1[2]-s2[2])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	} else{
		cout<<0;
	}
	
	
	return 0;
}
