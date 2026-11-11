#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
string a1,b1,f,g;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		cin.tie(0);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==b1[0] and a1[1]==b1[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((a1[2]=='D' or a1[2]=='F') and (b1[2]=='D' or b1[2]=='F')){
		cout<<11;
	}else if((a1[2]=='A' or a1[2]=='B' or a1[2]=='C') and (b1[2]=='A' or b1[2]=='B' or b1[2]=='C')){
		cout<<1;
		if(abs(a1[2]-b1[a])==1){
			cout<<1;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		cout<<"00";
	}
	return 0;
} 
