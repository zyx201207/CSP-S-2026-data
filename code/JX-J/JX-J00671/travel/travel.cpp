#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",std.in);
    freopen("travel.out","w",std.out);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0] and s1[1]==s2[1]){
            cout<<1;
            if(!(s1[2]=='D' and s2[2]=='C' or s2[2]=='D' and s1[2]=='C')){
                cout<<1;
                if(abs(s1[2]-s2[2])==1){
                    cout<<1;
                }
                else{
                    cout<<"0";
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }

    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
