#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int g[6]={};
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>c>>s>>c1>>s1;
    if(c==c1){
        g[1]=1;
        if(s[0]==s1[0]&&s[1]==s1[1]){
        g[2]=1;
        if((s[2]!='D'&&s[2]!='F'&&s1[2]!='D'&&s1[2]!='F')||(s[2]!='A'&&s[2]!='B'&&s[2]!='C'&&s1[2]!='A'&&s1[2]!='B'&&s1[2]!='C')){
            g[3]=1;
            //if((s[2]!='A'&&s1[2]!='C')&&(s[2]!='C'&&s1[2]!='A')){
                //cout<<1111<<endl;
                //return 0;
            //}
            if(s[2]=='A'&&s1[2]!='C') g[4]=1;
            if(s[2]=='C'&&s1[2]!='A') g[4]=1;
        }
    }
    }
    for(int i=1;i<=4;i++){
        cout<<g[i];
    }
    return 0;
}
