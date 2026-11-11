#include<bits/stdc++.h> 
using namespace std;
const int INF = 0x3f3f3f3f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char one,two;
	cin>>c1>>s1>>one>>c2>>s2>>two;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(((one=='A'||one=='B'||one=='C') && (two=='A'||two=='B'||two=='C')) ||((one=='D'||one=='F') && (two=='F'||two=='D'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	
	if(one+1==int(two)||two+1==int(one)){
		cout<<1;
	} else{
		cout<<0;
	}
	return 0;
	
}
