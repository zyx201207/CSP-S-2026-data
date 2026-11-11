#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a=1,b=1;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            cout<<"000";
            return 0;
        }
    }if(a==1){
        cout<<1;
    }if(s1[2]=='D' || s1[2]=='F'){
        if(s2[2]=='D' || s2[2]=='F'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
            cout<<1;
        }else{
            cout<<0;
        }
    }if(s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='A'){
        cout<<1;
        b=0;
    }else if(s1[2]=='B' && s2[2]=='C' || s1[2]=='C' && s2[2]=='B'){
        cout<<1;
        b=0;
    }else if(s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D'){
        cout<<1;
        b=0;
    }if(b==1){
        cout<<0;
    }
    return 0;
}
