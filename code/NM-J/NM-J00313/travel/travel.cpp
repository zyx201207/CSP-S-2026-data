#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string b,d;
    int a,c;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    else{
        if(b[0]!=d[0]||b[1]!=d[1]){
            cout<<"1000";
            return 0;
        }
        else{
            if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F')||(d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='F')){
                cout<<"1100";
                return 0;
            }
            else{
                if(b[2]!=d[2]+1&&b[2]!=d[2]-1){
                    cout<<"1110";
                    return 0;
                }
            }
        }
    }
    cout<<"1111";
    return 0;
}
