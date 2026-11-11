#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
string xc,xz,yc,yz;
cin>>xc>>xz>>yc>>yz;
if(xc!=yc||xc=="01"||xc=="16"||yc=="01"||yc=="16"){
    cout<<"0000";
    return 0;
}else{
    cout<<"1";
}

for(LL i=1;i=1;i++){
    if(i==1){
        if(xz[i]!=yz[i]){
            cout<<"000";
            return 0;
        }else{
            cout<<"1";
            break;
        }
    }
}
for(LL i=2;i=2;i++){
    if(i==2){
        if(xz[i]=='A'||xz[i]=='B'||xz[i]=='C'){
            if(yz[i]=='A'||yz[i]=='B'||yz[i]=='C'){
            cout<<"1";
            if(xz[i]=='A'&&yz[i]=='B'||xz[i]=='C'&&yz[i]=='B'){
            cout<<"1";
            }else if(yz[i]=='A'&&xz[i]=='B'||yz[i]=='C'&&xz[i]=='B'){
            cout<<"1";
            }else{
            cout<<"0";
            }
            return 0;
            }else{
            cout<<"00";
            return 0;
            }
        }else if(xz[i]=='D'||xz[i]=='F'){
            if(yz[i]=='D'||yz[i]=='F'){
            cout<<"11";
            return 0;
            }else{
            cout<<"00";
            return 0;
            }

        }else{
        cout<<"00";
        return 0;
        }
    }
}


return 0;
}
