#include<bits/stdc++.h>
#define iwill using
#define ak namespace
#define cspj std;
iwill ak cspj
string c1,c2,s1,s2;
string cx1="",cx2="",zw1,zw2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    cx1+=s1[0];
    cx1+=s1[1];
    cx2+=s2[0];
    cx2+=s2[1];
    zw1+=s1[2];
    zw2+=s2[2];
    if(cx1==cx2 && c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(cx1==cx2 && c1==c2){
        if(zw1=="D" && zw2!="F"){
            cout<<0;
            cout<<0;
        }
        else if(zw1=="F" && zw2!="D"){
            cout<<0;
            cout<<0;
        }
        else if(zw2=="F" && zw1!="D"){
            cout<<0;
            cout<<0;
        }
        else if(zw2=="D" && zw1!="F"){
            cout<<0;
            cout<<0;
        }
        else{
            cout<<1;
            if(zw1=="D" || zw2=="D"){
                cout<<1;
            }
            else if(zw1=="A" && zw2=="B"){
                cout<<1;
            }
            else if(zw1=="B" && zw2=="A"){
                cout<<1;
            }
            else if(zw1=="C" && zw2=="B"){
                cout<<1;
            }
            else if(zw1=="B" && zw2=="C"){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    else{
        cout<<0;
        cout<<0;
    }
    return 0;
}
///////////////////////
