#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]+s1[1]==s2[0]+s2[1]){
            cout<<"1";
            if(('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C')){
                cout<<"1";
                if(abs(s1[2]-s2[2])==1)cout<<"1";
                else cout<<"0";
            }else if(('D'<=s1[2]&&s1[2]<='E')&&('D'<=s1[2]&&s1[2]<='E')){
                cout<<"11\n";
            }else{
                cout<<"00\n";
            }
        }else{
            cout<<"000\n";
        }
    }else{
        cout<<"0000\n";
    }
    return 0;
}
