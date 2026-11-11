#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],c[2],d[3];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++){
        cin>>a[i];
	}
	for(int i=0;i<3;i++){
        cin>>b[i];
	}
	for(int i=0;i<2;i++){
        cin>>c[i];
	}
	for(int i=0;i<3;i++){
        cin>>d[i];
	}
	if(a!=c){
    cout<<"0000";
	return 0;
	}else {
	cout<<"1";
	if(b[0]==d[0]&&b[1]==d[1]){
	cout<<"1";
	if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
            cout<<"11";
            return 0;
    }
	else if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||b[2]=='C')){
	cout<<"1";
	if(b[2]=='B'||d[2]=='B')cout<<"1";
	else cout<<"0";
	}
	else{
            cout<<"00";
    return 0;
    }
	}else {
	cout<<"000";
	return 0;
	}
	}
	return 0;
}
