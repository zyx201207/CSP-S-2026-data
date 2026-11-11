#include<bits/stdc++.h>
using namespace std;
int fa,fb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]+s1[1]==s2[0]+s2[1]){
            cout<<"1";
            if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
                fa=1;
            }
            else{
                fa=2;
            }
            if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
                fb=1;
            }
            else{
                fb=2;
            }
            if(fa==fb){
                cout<<"1";
                if(fa==2){
                    cout<<"1";
                }
                else{
                    if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A')){
                        cout<<0;
                    }
                    else{
                        cout<<1;
                    }
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
