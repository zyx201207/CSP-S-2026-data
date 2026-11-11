#include<bits/stdc++.h>
using namespace std;
int ans[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,b1,b2;
    cin >> c1 >> c2 >>b1>>b2;
    if(c1==b1){
        ans[0]=1;
    }
    for(int i=0;i<2;i++){
        if(c2[i]==b2[i] && ans[0]==1){
            ans[1]=1;
        }
        else{
            ans[1]=0;
        }
    }
    if(ans[0]==1 && ans[1]==1){
        if(c2[2]<='C'&&b2[2]<='C'){
            ans[2]=1;
        }
        else if(c2[2]<='F'&&b2[2]<='F'&& c2[2]>'C'&&b2[2]>'C'){
            ans[2]=1;
            ans[3]=1;
        }
    }
    if(ans[0]==1 && ans[1]==1 && ans[2]==1){
        if(c2[2]=='B' || b2[2]=='B'){
            ans[3]=1;
        }
    }
    for(int i=0;i<4;i++){
        cout << ans[i];
    }
    return 0;
}
