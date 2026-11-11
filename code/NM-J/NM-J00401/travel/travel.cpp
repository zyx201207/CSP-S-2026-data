#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    char n,m;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==s1[0]&&c1[1]==s1[1]){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(c2[0]==s2[0]&&c2[1]==s2[1]){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }

    n=c2,m=s2;

    if(n[0]==m[0]&&n[1]==m[1]){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1[2]==m[2]&&n[1]==c1[1]){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }


    return 0;
}

