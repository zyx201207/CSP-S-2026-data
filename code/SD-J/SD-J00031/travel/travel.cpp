#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[5],a1[5];
	char b[5],b1[5];
	cin>>a>>a1>>b>>b1;
	if(a[0]==b[0]&&a[1]==b[1]&&a!="01"&&a!="16"){
		cout<<"1";
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<"1";
			int ai,bi;
			if(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'){
				ai=1;
			}else{
				ai=0;
			}
			if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
				bi=1;
			}else{
				bi=0;
			}
			if(ai==bi){
				cout<<"1";
				if(ai==0||a1[2]=='B'||b1[2]=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
}
