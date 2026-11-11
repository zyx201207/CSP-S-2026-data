#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c,s,tc,ts;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>s>>tc>>ts;
    if((c[0]!=tc[0])||(c[1]!=tc[1])){
        cout<<"0000";
    }else{
        if((s[0]!=ts[0])||(s[1]!=ts[1])){
            cout<<"1000";
        }else{
            if((s[2]=='D'&&ts[2]=='F')||(s[2]=='F'&&ts[2]=='D')){
                cout<<"1111";
            }else if(ts[2]=='B'){
                if((s[2]=='A')||(s[2]=='C')){
                    cout<<"1111";
                }else{
                    cout<<"1100";
                }
            }else if(s[2]=='B'){
                if((ts[2]=='A')||(ts[2]=='C')){
                    cout<<"1111";
                }else{
                    cout<<"1100";
                }
            }else if((s[2]=='A'&&ts[2]=='C')||(s[2]=='C'&&ts[2]=='A')){
                cout<<"1110";
            }else{
                cout<<"1100";
            }

        }
    }
    return 0;
}
