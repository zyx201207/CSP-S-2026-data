#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(!((s1[0]==s2[0])&&(s1[1]==s2[1]))){
        cout<<"000";
        return 0;
    }
    cout<<1;
    int a1=s1[2]-'A'+1,a2=s2[2]-'A'+1;
    if(a1>3){
        if(a2>3) cout<<11;
        else cout<<"00";
    } else{
        if(a2<4){
            cout<<1;
            if(abs(a1-a2)==1)
                cout<<1;
            else cout<<0;
        } else cout<<"00";
    }
    return 0;
}
