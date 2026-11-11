#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,aa,b,bb;
    cin>>a>>aa>>b>>bb;
    if(a==b){
        cout<<"1";
        if(aa[0]==bb[0]&&aa[1]==bb[1]){
            cout<<"1";
            if(aa[2]=='A'){
                if(bb[2]=='B'){
                    cout<<"11";
                    return 0;
                }
                if(bb[2]=='C'){
                    cout<<"10";
                    return 0;
                }
                if(bb[2]=='D'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='F'){
                    cout<<"00";
                    return 0;
                }
            }
            if(aa[2]=='B'){
                if(bb[2]=='A'){
                    cout<<"11";
                    return 0;
                }
                if(bb[2]=='C'){
                    cout<<"11";
                    return 0;
                }
                if(bb[2]=='D'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='F'){
                    cout<<"00";
                    return 0;
                }
            }
            if(aa[2]=='C'){
                if(bb[2]=='A'){
                    cout<<"10";
                    return 0;
                }
                if(bb[2]=='B'){
                    cout<<"11";
                    return 0;
                }
                if(bb[2]=='D'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='F'){
                    cout<<"00";
                    return 0;
                }
            }
            if(aa[2]=='D'){
                if(bb[2]=='A'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='B'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='C'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='F'){
                    cout<<"11";
                    return 0;
                }
            }
            if(aa[2]=='F'){
                if(bb[2]=='A'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='B'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='C'){
                    cout<<"00";
                    return 0;
                }
                if(bb[2]=='D'){
                    cout<<"11";
                    return 0;
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
