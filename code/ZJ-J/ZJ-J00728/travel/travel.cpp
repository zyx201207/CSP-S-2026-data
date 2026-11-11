#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool ok1,ok2,ok3,ok4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    ok2=1;
    if(c1==c2) ok1=1;
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            ok2=0;
            break;
        }
    }
    if(!ok2){
        cout<<"1000";
        return 0;
    }
    char a=s1[2],b=s2[2];
    if(a=='D'){
        if(b!='F'){
            cout<<"1100";
            return 0;
        }
        cout<<"1111";
        return 0;
    }
    if(a=='F'){
        if(b!='D'){
            cout<<"1100";
        }
        cout<<"1111";
        return 0;
    }
    if(b=='D'){
        if(a!='F'){
            cout<<"1100";
            return 0;
        }
        cout<<"1111";
        return 0;
    }
    if(b=='F'){
        if(a!='D'){
            cout<<"1100";
            return 0;
        }
        cout<<"1111";
        return 0;
    }
    if((a=='A'&&b=='C')||(a=='C'&&b=='A')) cout<<"1110";
    else cout<<"1111";
    return 0;
}
