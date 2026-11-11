#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;

    bool h=0;
    if(c1==c2){
        cout<<1;
        h=1;
    }
    else{
        cout<<0;
    }

    int o=s1.size(),k=s2.size();
    bool flage=1;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            flage=0;
        }
    }
    if(flage==1 && h==1){
        cout<<1;
    }
    else{
        cout<<0;
    }


    bool q=0;
    if(((s1[2]=='D' && s2[2]=='F') || (s2[2]=='D' && s1[2]=='F')) && flage==1&& h==1){
        q=1;
    }
    else if(s1[2] >= 'A' && s1[2]<='C' && s2[2] >= 'A' && s2[2]<='C' && flage==1&& h==1){
        q=1;
    }
    bool p=0;
    if(q==1 && flage==1 && h==1){
        cout<<1;
        p=1;
    }
    else{
        cout<<0;
    }


    if(p==1 && ((s1[2] >= 'A' && s1[2]<='C' && s2[2] >= 'A' && s2[2]<='C' && (s1[2]==s2[2]+1 || s1[2]==s2[2]-1)) || ((s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F')))){
       cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
