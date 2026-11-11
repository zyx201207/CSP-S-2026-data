#include<bits/stdc++.h>
using namespace std;
string c;
string s;
string c2;
string s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	int sum=0;
	string n="ABCDF";
	if(c==c2){
	    sum++;
    }
	if(s[0]==s2[0] and s[1]==s2[1]){
	    	sum+=10;
    }
    if(s[2]==n[0] and s2[2]==n[1]){
    	sum+=1100;
	}
	if(s[2]==n[1] and s2[2]==n[0]){
    	sum+=1100;
	}
	if(s[2]==n[1] and s2[2]==n[2]){
    	sum+=1100;
	}
	if(s[2]==n[2] and s2[2]==n[1]){
    	sum+=1100;
	}
	if(s[2]==n[2] and s2[2]==n[0]){
    	sum+=100;
	}
	if(s[2]==n[0] and s2[2]==n[2]){
    	sum+=100;
	}
	if(s[2]==n[3] and s2[2]==n[4]){
    	sum+=1100;
	}
	if(s[2]==n[4] and s2[2]==n[3]){
    	sum+=1100;
	}
    if(sum%10==0){
    	cout<<"0000";
	}
    if(sum==1 or sum==101 or sum==1001 or sum==1101){
    	cout<<"1000";
	}
	if(sum==11){
		cout<<"1100";
	}
	if(sum==111){
		cout<<"1110";
    }
    if(sum==1111){
    	cout<<"1111";
	}
	return 0;
}
			