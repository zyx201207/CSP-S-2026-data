#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(s1==s2){
        for(int i=1;i<=4;i++){
            cout<<0;
            return 0;
        }
    }
    if(c1==c2){
        cout<<1;
    }else{
        for(int i=1;i<=4;i++){
            cout<<0;
            return 0;
        }
    }
    int l=s1.size();
    bool b=true;
    for(int i=0;i<=1;i++){
        if(s1[i]==s2[i]){
            b=true;
        }else{
            b=false;
        }
    }
    if(b==true){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
        cout<<1;
    }else{
        cout<<0;
    }
    if((s1[2]==s2[2]&&abs(s1[1]+s1[0]*10-s2[1]+s1[0]*10)==1)||(s1[0]==s2[0]&&s1[1]==s2[1]&&abs(s1[2]-s2[2])==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
