#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int flag=1;
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]){
			continue;
		}
		flag=0;
	}
	if(flag){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;		
		return 0;
	}
	char a1=s1[2],a2=s2[2];
	int t1=0,t2=0;
	if(a1=='D' || a1=='F'){
		t1=1;
	}
	if(a2=='D' || a2=='F'){
		t2=1;
	}
	if(t1==t2){
		cout<<1;
	}else{
		cout<<0;
	}
	int qi=0;
	if(a1+1==a2 && a1!='C' && a2!='D'){
		qi=1;
	}
	if(a2+1==a1 && a2!='C' && a1!='D'){
		qi=1;
	}
	if(qi==1){
		cout<<1;
	}else{
		cout<<0;
	}	
	
	
	
	return 0;
}
