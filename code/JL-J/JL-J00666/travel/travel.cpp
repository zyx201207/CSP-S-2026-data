#include<bits/stdc++.h>
using namespace std;
bool lr(int a){
    if(a=='A'||a=='B'||a=='C'){
        return 1;
    }
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int s13,s23;
    cin>>c1>>s1>>c2>>s2;
    s13=s1[2];
    s23=s2[2];
    if(c1[1]==c2[1]&&c1[0]==c2[0]){
        cout<<"1";
        if(s1[1]==s2[1]&&s1[0]==s2[0]){
            cout<<"1";
            if(lr(s1[2])==lr(s2[2])){
                cout<<"1";
                if(lr(s1[2])==0) cout<<"1";
                else if(s13-s23==1||s13-s23==-1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
