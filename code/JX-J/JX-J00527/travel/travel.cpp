#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    //cout<<r1<<" "<<r2[2]<<" "<<x1<<" "<<x2[2];
    if(r1[0]==x1[0] and r1[1]==x1[1]) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(r2[0]==x2[0] and r2[1]==x2[1]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(r2[2]=='A'){
            if(x2[2]=='B' or x2[2]=='C'){
                    cout<<"1";
            }
    }
    else if(r2[2]=='B'){
            if(x2[2]=='A' or x2[2]=='C'){
                    cout<<"1";
            }
    }
    else if(r2[2]=='C'){
            if(x2[2]=='A' or x2[2]=='B'){
                    cout<<"1";
            }
            if(x2[2]=='D'){
                cout<<"00";
                return 0;

            }
    }
    else if(r2[2]=='D' and x2[2]=='E' or r2[2]=='E' and x2[2]=='D'){
            cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(r2[2]=='A' and x2[2]=='B' or r2[2]=='B' and r2[2]=='A') cout<<"1";
    else if(r2[2]=='C' and x2[2]=='B' or r2[2]=='B' and r2[2]=='C') cout<<"1";
    else if(r2[2]=='D' and x2[2]=='E' or r2[2]=='E' and r2[2]=='D') cout<<"1";
    else cout<<"0";
    return 0;
}

