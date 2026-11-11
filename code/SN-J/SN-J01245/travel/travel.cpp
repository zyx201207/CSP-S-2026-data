#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,q,w,e,r;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	for(int i=0;i<=2;i++){
		if(i==0||i==1){
			q=s1[i];
			e=s2[i];
		}else{
			w=s1[i];
			r=s2[i];
		}
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	} 
	
	if(c1==c2&&q==e){
		cout<<1;
	}else {
		cout<<0;
	}

	if(c1==c2&&q==e){
		if(w=="F"&&r=="D"||w=="D"&&r=="F"||w=="A"&&r=="B"||w=="A"&&r=="C"||w=="B"&&r=="C"||w=="B"&&r=="A"||w=="C"&&r=="A"||w=="C"&&r=="B"){
			cout<<1;	
		}
		else cout<<0;
	}

	if(c1==c2&&q==e){
		if(w=="F"&&r=="D"||w=="D"&&r=="F"||w=="A"&&r=="B"||w=="B"&&r=="C"||w=="B"&&r=="A"||w=="C"&&r=="B"){
			cout<<1;	
		}
		else cout<<0;
	}
}
