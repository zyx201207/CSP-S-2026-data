#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=2;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}  
		
	}
	cout<<1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}  
	}
	cout<<1;
	
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))  cout<<1;
	else{
		cout<<"00";
		return 0;
	} 
	if((s1[2]-'A')-(s2[2]-'A')==1||(s2[2]-'A')-(s1[2]-'A')==1)  cout<<1;
	else cout<<0;
	return 0;
} 

