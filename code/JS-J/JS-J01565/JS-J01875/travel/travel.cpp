#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000\n";
        return 0;
    }
    else{
        cout<<"1";
        if(s1.substr(0,2)!=s2.substr(0,2)){
            cout<<"000\n";
            return 0;
        }
        else{
            cout<<"1";
            int l1,l2;
            l1=l2=0;
            if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
                l1=1;
            }
            if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
                l2=1;
            }
            if(l1!=l2){
                cout<<"00\n";
                return 0;
            }
            else{
                cout<<"1";
                if(abs(s2[2]-s1[2])!=1 && (!(s1[2]=='D' && s2[2]=='F')) && (!(s2[2]=='D' && s1[2]=='F'))){
                    cout<<"0\n";
                    return 0;
                }
                else{
                    cout<<"1\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
/*
RP++
I will AK CSP-J2026
*/
