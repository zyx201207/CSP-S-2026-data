#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>x;
	cin>>b;
	cin>>y;
	if(a==b){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
		cout<<1;
		int n=x[2];
		int m=y[2];
		if((n=='A'&&m=='C')||(n=='C'&&m=='A')||(n=='B'&&m=='C')||(n=='C'&&m=='B')||(n=='A'&&m=='B')||(n=='B'&&m=='A')||(n=='D'&&m=='F')||(n=='F'&&m=='D')){
			cout<<1;
		}else{
		cout<<0;
		}
		if((n=='A'&&m=='B')||(n=='B'&&m=='A')||(n=='B'&&m=='C')||(n=='C'&&m=='B')||(n=='D'&&m=='F')||(n=='F'&&m=='D')){
		cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"000";
	}
	}else{
		cout<<"0000";
	}
	return 0;
}
