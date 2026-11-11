#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,c2,s2;
    cin>>c>>s>>c2>>s2;
    if(c==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if((s[0]==s2[0]&&s[1]==s2[1])&&(c==c2)){
        cout<<1;
    }else{
        cout<<0;
    }
    if((((s[2]<'D'&&s2[2]<'D')||(s[2]>'C'&&s2[2]>'C'))&&(s[0]==s2[0]&&s[1]==s2[1]))&&(c==c2)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(((((s[2]-s2[2]==1)||(s2[2]-s[2]==1)&&((s[2]<'D'&&s2[2]<'D')||(s[2]>'C'&&s2[2]>'C')))&&(s[0]==s2[0]&&s[1]==s2[1])))&&(c==c2)){
        cout<<1;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
