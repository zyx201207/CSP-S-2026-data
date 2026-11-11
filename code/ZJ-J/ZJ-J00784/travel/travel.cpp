#include<bits/stdc++.h>
using namespace std;
#define ll long long;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	for(int i=0;i<a1.size();i++){
		if(a1[i]!=b1[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<=1;i++){
		if(a2[i]!=b2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	char n1=a2[2],n2=b2[2];
	if(n1=='E'){
		if(n2=='D')cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(n1=='D'){
		if(n2=='E')cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(n1=='C'){
		if(n2=='B'||n2=='A')cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(n1=='B'){
		if(n2=='C'||n2=='A')cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(n1=='A'){
		if(n2=='B'||n2=='C')cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(abs(n1-n2)==1)cout<<1;
	else cout<<0;
	return 0;
}
