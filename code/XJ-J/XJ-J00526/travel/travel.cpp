#include <bits/stdc++.h>
using namespace std;     
string  a[3]={"a","b","c"};
string b[2]={"d","f"};
  
int main(){
freopen("travel.in","r",stdin);    freopen ("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1;
	cin>>s2;
	cin>>c2;
	cin>>s2;
	if(c1==c2){
		cout<<1;
	}
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else cout<<0;
	int c,d;
//	for(int i=0;i<=5;i++){
//		if(s1[2]==a[i]){
//			c=i;
//		}
//		if(s2[2]==a[i]){
//			d=i;
//		}
//	}
//	
//	if(c<=2&&d<=2){
//		cout<<1;
//	}
//	else if(c==3&&d==4){
//		cout<<1;
//	}
//	else{
//		cout<<00;
//		return 0;
//	}
//	
//	if(c+1==d||c-1==d){
//		cout<<1;
//	}
//	else cout<<0;
	for(s1[2]=="a"||s1[2]=="b"||s1[2]=="c"&&s2[2]=="a"||s2[2]=="b"||s2[2]=="c"){
		cout<<1;
	}
	else cout<<0;
	
	if(s1[2]+1==s2[2]){
		cout<<1;
	}
	else if(s1[2]-1==s2[2]){
		cout<<1;
	}
	
	else cout<<0;
	
	return 0;}