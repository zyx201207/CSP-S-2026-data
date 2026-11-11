#include<bits/stdc++.h>
using namespace std;
string s,t,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>a>>t>>b;
	if(s==t){
		cout<<"1";
		if(a[0]+a[1]==b[0]+b[1]){
			cout<<"1";
			if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')){
				cout<<"1";
				if(abs(a[2]-b[2])==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')){
				cout<<"11";
			}else{
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
