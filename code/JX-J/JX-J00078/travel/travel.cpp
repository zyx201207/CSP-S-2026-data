#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(s2[2]-'0'>19 and s1[2]-'0'>19){
        int flag=1;
    }
    int a=s1[2]-'0';
    int b=s2[2]-'0';
    int c=a-b;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0] and s1[1]==s2[1]){
            cout<<1;
            if(s1[2]-'0'<=19 and s2[2]-'0'<=19 or s1[2]-'0'>19 and s2[2]-'0'>19){
                cout<<1;
                if(c==1 or c==-1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<00;
            }
        }else{
            cout<<000;
        }
    }else{
        cout<<0000;
    }
    return 0;
}
