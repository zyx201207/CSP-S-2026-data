#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,a="ABC";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<"1";
    }
    if(s1[0]+s1[1]!=s2[0]+s2[1]){
        cout<<"000";
        return 0;
    }
    else{
        cout<<"1";
    }
    int pos1,pos2;
    bool f1=false,f2=false;
    for(int i=0;i<3;i++){
        if(a[i]==s1[2]){
            f1=true;
            pos1=i;
        }
        if(a[i]==s2[2]){
            f2=true;
            pos2=i;
        }
    }
    if(f1==false&&f2==false){
        cout<<"11";
    }
    else if(f1==f2){
        cout<<"1";
        if(pos1==pos2+1||pos1+1==pos2){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    else{
        cout<<"00";
    }
    return 0;
}
