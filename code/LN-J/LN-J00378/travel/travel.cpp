#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rz,xc,xz;
    cin>>rc>>rz>>xc>>xz;
    string ans="0000";
    if(rc==xc){
		ans[0]='1';
		if(rz.substr(0,2)==xz.substr(0,2)){
        ans[1]='1';
        if(rz[2]<='C'&&xz[2]<='C'||rz[2]>='D'&&xz[2]>='D'){
            ans[2]='1';
            if(abs(rz[2]-xz[2])==1) ans[3]='1';
			}
		}
	}
    cout<<ans;
    return 0;
}
