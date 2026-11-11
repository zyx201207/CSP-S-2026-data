#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3 || s1=="01" || s1=="16"){
		cout<<"0000";
		return 0;
	}
	int a=0,b=0;
	a=10*(s2[0]-'0')+(s2[1]-'0');
	b=10*(s4[0]-'0')+(s4[1]-'0');
	if(b==a){
		cout<<"11";
		int x=0,y=0,z,w;
		if((s2[2]=='A') || (s2[2]=='C') || (s2[2]=='B')){
			x=1;
		} 
		z=s2[2]-'0';
		
		if((s4[2]=='A') || (s4[2]=='B') || (s4[2]=='C')){
			y=1;
		} 
		w=s4[2]-'0';
		
		if(x==y){
			cout<<"1";
		}
		else{
			cout<<"00";
			return 0;
		}
		if((w+1==z) || (z+1==w)){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
	    cout<<"1000";
    }
	return 0;
}
