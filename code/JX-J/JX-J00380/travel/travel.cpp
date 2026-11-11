#include<bits/stdc++.h>
using namespace std;
int a,b;
int c,d;
char s,st;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>s>>b>>d>>st;
	if(a==b){
		cout<<"1";
		if(c==d){
			cout<<"1";
			if((s<='C'&&st<='C')||(s>'C'&&st>'C')){
				cout<<"1";
				if(abs(st-s)==1) cout<<"1";
				else cout<<"0";
			}else {
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
