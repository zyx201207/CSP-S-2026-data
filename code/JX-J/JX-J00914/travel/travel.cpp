#include<bits/stdc++.h>
using namespace std;
int a,b,dick=0,flag=1;
string s1,s2;
int ll=0,cc=0;
int main(){
 // freopen("travel.in","r",stdin);
  //freopen("travel.out","w",stdout);
	cin>>a>>s1;
	cin>>b>>s2;
	if(a==b){
		cout<<"1";
		dick=1;
	}
	else {
        cout<<"0000";
		return 0;
	}

	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag=0;
		}
	}
	if(flag==0){
		cout<<"0";
	}
	else if(flag==1&&dick==1){
		cout<<"1";
		}
///////////////////////////////////////////////
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
			cout<<"1";
			cc=1;
    }
    else if(s1[2]=='D'||s1[2]=='F'){
		if(s1[2]=='D'||s1[2]=='F'){
			cout<<"1";
			ll=1;
			cc=1;
			}
		}
	else {
		cout<<"0";
		}
//////////////////////////////////////////////
		if(ll==1||s1[2]=='B'||s2[2]=='B'){
			cout<<"1";
			return 0;
			}
			else cout<<"0";
	return 0;
}
