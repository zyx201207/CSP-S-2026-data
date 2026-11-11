#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool vis1=false,vis2=false,vis3=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << '1';
        vis1=true;
    }
    else{
        cout << '0';
    }
    if(vis1){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout << '1';
            vis2=true;
        }
        else{
            cout <<'0';
        }
    }
    else{
        cout << '0';
    }
    if(vis2&&vis1){
        if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C')){
            cout << '1';
            vis3=true;
        }
        else{
            cout << '0';
        }
    }
    else{
        cout << '0';
    }
    if((vis1&&vis2)&&vis3){
        if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){
            cout << '1';
        }
        else{
            cout << '0';
        }
    }
    else{
        cout << '0';
    }
    return 0;
}
