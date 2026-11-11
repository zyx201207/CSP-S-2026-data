#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int b=0,h=0;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;	
	}
	else{	
	cout<<1;
	}
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			b=1;
		}
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			h=1;
		}
		if(h==b){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
		if(s2[2]+2==s1[2]||s1[2]+2==s2[2]){
			cout<<0;
			return 0;
		}
		cout<<1;
	return 0;
}

