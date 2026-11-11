#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int i=0;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		i+=1;
	}
	int a,b;
	a=s1[0]+s1[1];
	b=s2[0]+s2[1];
	if(i!=1){
		if(a==b){
			cout<<1;
		}
		else{
			cout<<"000";
			i+=1;
		}
	}
	int r=s1[2],x=s2[2];
	if(i!=1){
		if(r==68&&x==70||r==68&&x==70){ 
			cout<<1;
			return 0;
		}
		else if(r!=68 && x!=68 && r!=70 && x!=70){
			cout<<1;
		}
		else{
			cout<<"00";
			i+=1;
		}
	}
	if(i!=1){
		if(r-x==1 || x-r==1){
			cout<<1;
		}
		else if(r==68 && x==70 || r==70 && x==68){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
