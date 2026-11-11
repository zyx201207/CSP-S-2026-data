#include<bits/stdc++.h>
using namespace std;
string cone,sone,ctwo,stwo;
int ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cone>>sone>>ctwo>>stwo;
    for(int i=0;i<2;i++) if(cone[i]==ctwo[i]) ans++;
    if(ans==2) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    ans=0;
    for(int i=0;i<2;i++) if(sone[i]==stwo[i]) ans++;
    if(ans==2){
        cout<<"1";
        if((sone[2]=='C'&&stwo[2]=='D')||(sone[2]=='D'&&stwo[2]=='C')){
            cout<<"00";
            return 0;
        }
        else{
            cout<<"1";
            if((sone[2]=='A'&&stwo[2]=='B')||(sone[2]=='B'&&stwo[2]=='A')||(sone[2]=='B'&&stwo[2]=='C')||(sone[2]=='C'&&stwo[2]=='B')||(sone[2]=='D'&&stwo[2]=='F')||(sone[2]=='F'&&stwo[2]=='D')){
                cout<<"1";
                return 0;
            }
            else{
                cout<<"0";
                return 0;
            }
        }
    }
    else{
        cout<<"000";
        return 0;
    }
    return 0;
}
