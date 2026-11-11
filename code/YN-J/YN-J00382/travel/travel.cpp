#include<bits/stdc++.h>
using namespace std;
//#define long long long long
//#define long long unsigned long long
//priority_queue<int> sb;
//const long long maxn=1e5+13;
string a1,a2,b1,b2;
bool a=0,b=0,pd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
		a=1;
	}
	if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
		b=1;
	}
	if(a==b&&a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
		pd=1;
	}else{
		cout<<0;
	}
	if(abs(a2[2]-b2[2])==1&&pd==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
