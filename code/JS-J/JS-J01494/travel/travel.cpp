#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;cin>>c1>>c2>>s1>>s2;
    bool f=1;
    if(c1!=s1){
        cout<<0;
        f=0;
    }else{
        cout<<1;
    }
    if(c2[0]!=s2[0]||c2[1]!=s2[1]||!f){
        cout<<0;
        f=0;
    }else{
        cout<<1;
    }
    if(c2[2]>='A'&&c2[2]<='C'){
        if((s2[2]>='A'&&s2[2]<='C')&&f){
            cout<<1;
        }else{
            cout<<0;
            f=0;
        }
    }else{
        if((s2[2]>='D'&&s2[2]<='F')&&f){
            cout<<1;
        }else{
            cout<<0;
            f=0;
        }
    }
    if(f){
        if(c2[2]=='A'){
            if(s2[2]=='B')cout<<1;
            else cout<<0;
        }else if(c2[2]=='B'){
            if(s2[2]=='A'||s2[2]=='C')cout<<1;
            else cout<<0;
        }else if(c2[2]=='C'){
            if(s2[2]=='B')cout<<1;
            else cout<<0;
        }else if(c2[2]=='D'){
            if(s2[2]=='F')cout<<1;
            else cout<<0;
        }else if(c2[2]=='F'){
            if(s2[2]=='D')cout<<1;
            else cout<<0;
        }
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
