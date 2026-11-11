#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int hs(){
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C') return 1;
	}
	if(b[2]=='D'||b[2]=='F'){
		if(d[2]=='D'||d[2]=='F') return 1;
	}
	return 0;
}
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(hs()){
				cout<<1;
				if(abs(b[2]-d[2])==1&&b[2]!='D'&&d[2]!='D'){
					cout<<1;
				}else if(abs(b[2]-d[2])==2&&(b[2]=='F'||d[2]=='F')){
					cout<<1;
				}else{
					cout<<0;
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
	return 0;
}
