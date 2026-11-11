#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;	
	}
	int x=s1;
	int y=s2;
	if(x==y){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;	
	} 
	if(s1<'C'&&s2<'c'){
		cout<<1;
	}
	if(s1>'C'&&s2>'C'){
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	cout<<1;
	return 0;
}
