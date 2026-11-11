#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	string s3=s1.substr(0,2),s4=s2.substr(0,2);
	if(s3==s4){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	s3=s1.substr(2,1);
	s4=s2.substr(2,1);
	int f=0;
	if(s3[0]=='A'||s3[0]=='B'||s3[0]=='C'){
		if(s4[0]=='A'||s4[0]=='B'||s4[0]=='C'){     
			f=1;
		}
	}
	else{
		if(s4[0]=='D'||s4[0]=='F'){
			f=1;
		}
	}
	if(f==1){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(s3[0]+1==s4[0]||s3[0]-1==s4[0]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
