#include<bits/stdc++.h>
using namespace std;
string s1;
string s2;
string c1;
string c2;
int main(){
	freopen("teavel.in","r",stdin);
	freopen("teavel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=1;i++){
		if(c1==c2){
			cout<<1;	
		}else{
			cout<<"0000";
			break;
		} 
	
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
		}else{
			cout<<"000";
			break;
		} 
	
		if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
			cout<<"00";
			break;
		}else cout<<1;
	
		if(s2[2]=='D'&&s1[2]=='F'||s2[2]=='F'&&s1[2]=='D'){
			cout<<1;
		}else if(s1[2]==s2[2]-1||s1[2]-1==s2[2]){
	 		if(s2[2]=='D'&&s1[2]=='C'||s1[2]=='D'&&s2[2]=='C') cout<<0;
			else cout<<1;
		}else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
