#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1;
    string c2;
    char s1[4]={};
    char s2[4]={};
    cin>>c1;
    for(int i=0;i<3;i++){
        cin>>s1[i];
    }
    cin>>c2;
    for(int i=0;i<3;i++){
        cin>>s2[i];
    }//1
    if(c1==c2){
        cout<<"1";
    }else cout<<"0";
    //2
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
        }else cout<<"0";
    }else cout<<"0";
    //3
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(s1[2]<'D'&&s2[2]<'D'){
                cout<<"1";
            }else{
                if(s1[2]>'C'&&s2[2]>'C'){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }
        }
    }else cout<<"0";
    //4
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(s1[2]<'D'&&s2[2]<'D'){
                if(s1[2]=='B'||s2[2]=='B'){
                    cout<<"1";
                }else cout<<"0";
            }else{
                if(s1[2]>'C'&&s2[2]>'C'){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }
        }
    }else cout<<"0";
    return 0;
}
